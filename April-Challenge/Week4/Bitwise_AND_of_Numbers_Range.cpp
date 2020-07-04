#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:

    //Epicman @AnmolMajithia
    int rangeBitwiseAnd(int m, int n) {
        while(n>m){
            n&=n--;
        }
        return m&n;
    }

    //Iterative simple logic - Fastest
    /*int rangeBitwiseAnd(int m, int n){
        int count=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            count++;
        }
        return m<<count;
    }*/

    // LC guy- god tier sol. Same logic as iterative
    /*int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }*/

};

int main(){
    Solution solve;
    //	int inpsize=0;
    int input, m, n;
    //	cin>>inpsize;
    cin>>m;
    cin>>n;
    cout<<solve.rangeBitwiseAnd(m, n)<<endl;
    return 0;
}
