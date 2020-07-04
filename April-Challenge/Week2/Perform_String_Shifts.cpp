#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int totShift=0;
        string res;
        for(auto i: shift){
            if(i[0]){
                totShift+=i[1];
            }
            else{
                totShift-=i[1];
            }
        }
        if(totShift>0){
            totShift=totShift%s.length();
            totShift=s.length()-totShift;
        }
        else{
            totShift=abs(totShift);
            totShift=totShift%s.length();
        }
        res=s.substr(totShift);
        res+=s.substr(0,totShift);
        return res;
    }
};

int main()
{
    return 1;
}
