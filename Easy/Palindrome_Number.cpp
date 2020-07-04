#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int res=0, temp=x;
        if(x<0){
            return false;
        }
        while(x!=0){
            if(res>INT_MAX/10 or res<INT_MIN/10){
                return false;
            }
            res*=10;
            res+=x%10;
            x/=10;
        }
        return res==temp;

    }
};

int main(){
	Solution solve;
	int input;
	cin>>input;
	cout<<solve.isPalindrome(input)<<endl;
	return 0;
}
