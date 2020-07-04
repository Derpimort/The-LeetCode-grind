#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
        

    int minPathSum(vector<vector<int>>& grid){
        int gs0, gs1;
        if(grid.empty())
        {
            return 0;
        }
        gs0=grid.size();
        gs1=grid[0].size();
        for(int i=1;i<gs0;i++)
        {
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<gs1;i++)
        {
            grid[0][i]+=grid[0][i-1];
        }

        for(int i=1;i<gs0;i++)
        {
            for(int j=1;j<gs1;j++)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[gs0-1][gs1-1];
    }
    //Recursion TLE
    /*int pathSum(vector<vector<int>>&grid, int i, int j){
        if(i==grid.size()-1 && j==grid[i].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[i].size()){
            return INT_MAX;
        }
        return grid[i][j]+min(pathSum(grid, i+1, j), pathSum(grid, i, j+1));

    }
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        return pathSum(grid, 0, 0);
    }*/
};

int main(){
    return 1;
}
