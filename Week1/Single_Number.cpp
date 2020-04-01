#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	void printArr(vector<int>& nums){
		for (int i=0;i<nums.size();i++)
			cout<<nums[i]<<",";
		cout<<"\n";
	}

    	int singleNumber(vector<int>& nums) {
		int vsize=nums.size()-1;
		sort(nums.begin(), nums.end());
		int solo=nums[vsize];
		for(size_t num=0 ; num<vsize ; num+=2){
		    if(nums[num]!=nums[num+1]){
			solo = nums[num];
			break;
		    }
		}
		return solo;
		}
		//BS
		/*int vsize=nums.size();
        	int solo = nums[vsize-1];
        	vector<int>::iterator index;
        	for (size_t num=0 ; num < vsize;num++){
			cout<<num<<"\t"<<vsize<<"\t";
			printArr(nums);
			index=find(nums.begin()+num+1,nums.end(), nums[num]);
			if(index!=nums.end()){
				nums.erase(index);
				vsize--;
			}
			else{
				solo=nums[num];
				break;
			}
		}
		return solo;*/

		// StackOverflow
		/*int vsize=nums.size();
        	int solo=0;
        	for(int i=0;i<vsize;i++)
                	solo^=nums[i];
        	return solo;*/



};

int main(){
	Solution solve;
//	int inpsize=0;
	int input;
	vector<int> nums;
//	cin>>inpsize;
	while(cin>>input)
		nums.push_back(input);
	cout<<solve.singleNumber(nums)<<"\n";
	return 0;
}
