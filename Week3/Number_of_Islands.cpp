#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int gs0,gs1;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=gs0 || j<0 || j>=gs1 || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        if(grid.size()==0){
            return 0;
        }
        gs0=grid.size();
        gs1=grid[0].size();
        for(int i=0;i<gs0;i++){
            for(int j=0;j<gs1;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
};

int main(){
    return 1;
}
