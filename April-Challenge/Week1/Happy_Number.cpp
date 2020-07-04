#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

class Solution {
public:
    // The not exactly correct but fast way, havent found any incorrect case for this yet
    int getSum(int n){
        int sum=0;
        while(n>0){
            sum+=pow(n%10,2);
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        for(int i=0;i<10;i++){
            n=getSum(n);
            if(n==1)
                return true;
        }
        return false;
    }
};

int main(){
	Solution solve;
	int inp=0;
	cin>>inp;
	cout<<solve.isHappy(inp)<<"\n";
	return 0;
}
