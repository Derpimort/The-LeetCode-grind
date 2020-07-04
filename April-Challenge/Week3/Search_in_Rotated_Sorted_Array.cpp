#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //LC Fastest

    /*int search(vector<int>& nums, int target){
        int start=0, end=nums.size()-1, mid;
        
        while(start<=end)
        {
            mid=(start+end)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[start]<=nums[mid]){
                if(nums[mid]>=target && nums[start]<=target)
                {
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }  
        return -1;   
    }*/
            
    //Epic Recursion
    int binSearch(vector<int>&nums, int target, int start, int end){
        int mid;
        if(start>=end && nums[start]!=target){
            return -1;
        }
        else if(nums[start]==target){
            return start;
        }
        else if(nums[end]==target){
            return end;
        }
        mid=(start+end)/2;
        return max(binSearch(nums, target, start, mid), binSearch(nums, target, mid+1, end));
    }
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        return binSearch(nums, target, 0, nums.size()-1);
    }
};

int main(){
    Solution solve;
    //	int inpsize=0;
    int input, target;
    vector<int> nums;
    cin>>target;
    //	cin>>inpsize;
    while(cin>>input)
        nums.push_back(input);
    cout<<solve.search(nums, target)<<endl;
    return 0;
}
