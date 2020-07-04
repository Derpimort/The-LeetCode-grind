#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //The single line submission boner
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0),nums.end(),0);

        for(auto i: nums)
            cout<<i<<" ";
        cout<<"\n";   
    }

    //Wrong but works in LC for some reason
    /*void moveZeroes(vector<int>& nums) {
        nums.erase(
            std::remove(nums.begin(), nums.end(), 0),
            nums.end());
        //nums.shrink_to_fit();
        nums.resize(nums.capacity(),0);
        for(auto i: nums)
            cout<<i<<" ";
        cout<<"\n";   
        
    }
    */
};

int main(){
	Solution solve;
//	int inpsize=0;
	int input;
	vector<int> nums;
//	cin>>inpsize;
	while(cin>>input)
		nums.push_back(input);
	solve.moveZeroes(nums);
	return 0;
}
