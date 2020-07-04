#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            if(res>INT_MAX/10 or res<INT_MIN/10){
                return 0;
            }
            res*=10;
            res+=x%10;
            x/=10;
        }
        return res;
    }
};

int main(){
	Solution solve;
	int input;
	cin>>input;
	cout<<solve.reverse(input)<<endl;
	return 0;
}
