#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    /*int countElements(vector<int>& arr) {
        int num=0;
        vector<int>::iterator beg=arr.begin(),end=arr.end();
        for(int a:arr){
            if(find(beg,end,a+1)!=end){
                num+=1;
            }
        }
        return num;
    }*/

    //Fastest on LC
    int countElements(vector<int>& arr) {
        int res=0;
        map<int,int> nums;
        map<int,int>::iterator end;
        for(int a:arr){
            nums[a]+=1;
        }
        end=nums.end();
        for(auto a:nums){
            if(nums.find(a.first+1)!=end){
                res+=a.second;
            }
        }
        return res;
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
	cout<<solve.countElements(nums)<<endl;
	return 0;
}
