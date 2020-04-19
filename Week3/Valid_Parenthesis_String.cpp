#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    //Recursion TLE
    /*bool checkString(string s, int stck){
         for(int i=0,slen=s.length();i<slen;i++){
            if(s[i]=='('){
                stck++;
            }
            else if(s[i]==')'){
                if(stck==0)
                    return false;
                else
                    stck--;
            }
            else{
                s.replace(i,1,"(");
                if(checkString(s.substr(i),stck)){
                    return true;
                }
                s.replace(i,1,")");
                if(checkString(s.substr(i),stck)){
                    return true;
                }
            }
        }
        if(stck){
            return false;
        }
        return true;
    }
    bool checkValidString(string s) {
        int stck=0;
        return checkString(s,stck);
    }*/

    //LC Fastest
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (char c: s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = max(lo, 0);
        }
        return lo == 0;
    }
};

int main(){
    string s;
    Solution solve;
    cin>>s;
    cout<<solve.checkValidString(s)<<"\n";
    return 1;
}
    
