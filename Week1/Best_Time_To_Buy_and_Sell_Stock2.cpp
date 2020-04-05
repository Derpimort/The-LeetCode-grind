#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool bought=false;
        int tp=0,currp=0,i;
        int vs=prices.size();
        for(i=1;i<vs;i++)
        {
            if(prices[i-1]<prices[i] && !bought){
                currp=prices[i-1];
                bought=true;
            }
            else if(prices[i-1]>prices[i] && bought){
                tp+=prices[i-1]-currp;
                bought=false;
            }
        }
        if(bought){
            tp+=prices[i-1]-currp;
        }
        return tp;
    }
};

int main(){
	Solution solve;
//	int inpsize=0;
	int input;
	vector<int> nums;
//	cin>>inpsize;
	while(cin>>input)
		nums.push_back(input);
	cout<<solve.maxProfit(nums)<<endl;
	return 0;
}
