#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:

    //LC Fastest
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, count=0;
        map<int,int>hashm;
        hashm[0]++;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            count+=hashm[sum-k];
            hashm[sum]++;
        }
        return count;
    }
    //Brute-Force
    /*int subarraySum(vector<int> nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum=0;
            for (int end = start; end < nums.size(); end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }*/
};

int main(){
    Solution solve;
    //	int inpsize=0;
    int input, k;
    vector<int> nums;
    //	cin>>inpsize;
    cin>>k;
    while(cin>>input)
        nums.push_back(input);
    cout<<solve.subarraySum(nums, k)<<endl;
    return 0;
}
