#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //The first
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int prevSum=nums[0];
        for(int num : nums){
            sum+=num;
            if(sum<num)
                sum=num;
            if(sum>prevSum)
                prevSum=sum;
        }
        return prevSum;
    }

    //The Fast
    /*int maxSubArray(vector<int>& nums) {
        int sum=0;
        int prevSum=nums[0];
        for(vector<int>::iterator it = nums.begin(), end= nums.end(); it != end; ++it){
            sum+=*it;
            if(sum<*it)
                sum=*it;
            if(sum>prevSum)
                prevSum=sum;
        }
        return prevSum;
    }*/

    //The i tried to make it faster
    /*int maxSubArray(vector<int>& nums) {
        int sum=0;
        int nSize=nums.size();
        int * numbers=nums.data();
        int prevSum=nums[0];
        for(int i=0;i<nSize;i++){
            sum+=numbers[i];
            if(sum<numbers[i])
                sum=numbers[i];
            if(sum>prevSum)
                prevSum=sum;
        }
        return prevSum;
    }*/
    
    //The i tried to make it faster pt2
    /*int maxSubArray(vector<int>& nums) {
        int sum=0;
        int prevSum=nums[0];
        for(vector<int>::iterator it = nums.begin(), end= nums.end(); it != end; ++it){
            if((sum+*it)<*it)
                sum=*it;
            else
                sum+=*it;
            if(sum>prevSum)
                prevSum=sum;
        }
        return prevSum;
    }*/    
};

int main(){
	Solution solve;
//	int inpsize=0;
	int input;
	vector<int> nums;
//	cin>>inpsize;
	while(cin>>input)
		nums.push_back(input);
	cout<<solve.maxSubArray(nums)<<"\n";
	return 0;
}
