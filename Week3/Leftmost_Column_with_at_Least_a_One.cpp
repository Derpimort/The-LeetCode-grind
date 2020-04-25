#include<iostream>
#include<vector>

using namespace std;

class BinaryMatrix {
public:
    int get(int x, int y);
    vector<int> dimensions();
  };

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims=binaryMatrix.dimensions();
        int i=0, j=dims[1]-1;
        while(i<dims[0] && j>=0){
            if(binaryMatrix.get(i,j)==1){
                j--;
            }
            else{
                i++;
            }
        }
        return j==dims[1]-1?-1:j+1;
    }
};

int main(){
    return 1;
}
