#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    //LC DP similar to LCS
    int maximalSquare(std::vector<std::vector<char>> mat){
        int rows=mat.size();
        if(rows==0){
            return 0;
        }
        int cols=mat[0].size();

        int dp[rows+1][cols+1];
        memset(dp, 0, (rows+1)*(cols+1)*sizeof(int));
        int maxlen=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++)
            {
                if(mat[i-1][j-1]=='1'){
                    dp[i][j]=std::min(std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
                    maxlen=std::max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen * maxlen;
    }

    //LC BruteForce
    /*int maximalSquare(std::vector<std::vector<char>> mat){
        int rows=mat.size();
        if(rows==0){
            return 0;
        }
        int cols=mat[0].size();
        int maxlen=0, currlen;
        bool flag;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
            {
                if(mat[i][j]=='1'){
                    currlen=1;
                    flag=true;
                    while((currlen+i)<rows & (currlen+j)<cols && flag){
                        for(int k=j;k<=currlen+j;k++){
                            if(mat[i+currlen][k]=='0'){
                                flag=false;
                                break;
                            }
                        }
                        for(int k=i;k<=currlen+i;k++){
                            if(mat[k][j+currlen]=='0'){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            currlen++;
                        }
                    }
                    if(currlen>maxlen){
                        maxlen=currlen;
                    }
                }
            }
        }
        return maxlen * maxlen;
    }*/
};

int main(){
    Solution solve;
    int m,n;
    char letter;
    cin>>m;
    cin>>n;
    vector<vector<char>> mat(m, vector<char> (n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>letter;
            mat[i][j]=letter;
        }
    }
    cout<<solve.maximalSquare(mat)<<endl;
}
