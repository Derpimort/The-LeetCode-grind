#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

    //LC FASTEST
    int findMaxLength(std::vector<int>& nums){
        int maxlen=0,count=0,ns=nums.size();
        int arr[ns*2+1];
        fill_n(arr,ns*2+1,-2);
        arr[ns]=-1;
        for(int i=0;i<ns;i++){
            count+=nums[i]==0?-1:1;
            if(arr[count+ns]>-2){
                maxlen=max(maxlen, i-arr[count+ns]);
            }
            else{
                arr[count+ns]=i;
            }
        }
        return maxlen;
    }
    // The Internet - FAST O(n)?
    /*int findMaxLength(std::vector<int>& nums){
        int maxlen=0,sum=0,ns=nums.size();
        unordered_map<int, int> hmap;
        unordered_map<int, int>::iterator it;
        hmap[0]=-1;
        for(int i=0;i<ns;i++){
            sum+=nums[i]==0?-1:1;
            if((it=hmap.find(sum))!=hmap.end()){
                maxlen=max(maxlen, i-it->second);
            }
            else{
                hmap.insert({sum,i})
            }
        }
        return maxlen;
    }*

    //Brute Force TLE O(shit)
    /*int findMaxLength(vector<int>& nums) {
        int i=0, maxlen=0, ones=0,zeros=0, currmax=0, ns=nums.size();
        while(maxlen<(ns-i)){
            ones=0;
            zeros=0;
            for(int j=i;j<ns;j++){
                if(nums[j]==0)
                zeros+=1;
                else
                ones+=1;
                if(ones==zeros){
                    currmax=j-i+1;
                }
            }
            maxlen=max(currmax,maxlen);
            i++;
        }
        return maxlen;
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
    cout<<solve.findMaxLength(nums)<<"\n";
    return 0;
}
