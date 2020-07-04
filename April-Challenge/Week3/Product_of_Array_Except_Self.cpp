#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ns=nums.size(), mul=nums[ns-1];
        vector<int> res(ns,1);
        for(int i=1;i<ns;i++){
            res[i]=nums[i-1]*res[i-1];
        }
        for(int i=ns-2;i>=0;i--){
            res[i]*=mul;
            mul*=nums[i];
        }
        return res;
    }

    // Division

    /*vector<int> productExceptSelf(vector<int>& nums) {
        int ns=nums.size(), mul=1;
        vector<int> res;
        for(int i=0;i<ns;i++){
            mul*=nums[i];
        }
        for(int i=0;i<ns;i++){
            res.push_back(mul/nums[i]);
        }
        return res;
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
    for(auto i: solve.productExceptSelf(nums))
        cout<<i<<"\t";
    cout<<endl;
    return 0;
}
