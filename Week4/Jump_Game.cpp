#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;


class Solution {
public:

    //LC top tier idk htf
    bool canJump(vector<int>& nums) {
        int ns = nums.size();
        int maxr=0;
        for (int i=0; i<=maxr;i++) {
            maxr=std::max(maxr, i+nums[i]);
            if(maxr>=ns-1)
                return true;
        }
        return false;
    }

    //LC-fastest greedy
    /*bool canJump(vector<int>& nums) {
        int lastPos=nums.size() - 1;
        for (int i=lastPos;i >= 0;i--) {
            if (i+nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
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
    cout<<solve.canJump(nums)<<endl;
    return 0;
}
