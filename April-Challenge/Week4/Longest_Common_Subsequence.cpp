#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    //DP
    int longestCommonSubsequence(string &a, string &b) {
        if (b.size()>a.size())
            return longestCommonSubsequence(b, a);

        int m=a.size(), n=b.size();
        int dp[2][m+1];
        memset(dp, 0, 2*(m+1)*sizeof(int));

        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (a[i-1] == b[j-1])
                    dp[i%2][j] = dp[(i-1) % 2][j-1]+1;
                else
                    dp[i%2][j] = max(dp[(i-1) % 2][j], dp[i % 2][j-1]);
            }
        }
        return dp[m%2][n];
    }
};

int main(){
    string s1, s2;
    Solution solve;
    cin>>s1;
    cin>>s2;
    cout<<solve.longestCommonSubsequence(s1,s2)<<endl;
}
