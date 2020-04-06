#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> f;
        map <string, vector<string>> res;
        string temp;
        for(int i=0;i<strs.size();i++)
        {
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            res[strs[i]].push_back(temp);
        }
        for(map<string, vector<string>>::iterator it=res.begin();it!=res.end();it++){
            f.push_back(it->second);
            for(auto s: it->second){
                cout<<s<<"\t";
            }
            cout<<endl;
        }
        return f;
    }
};

int main(){
	Solution solve;
	int inpsize=0;
	string input;
	vector<string> s;
	cin>>inpsize;
	while(inpsize--){
                cin>>input;
		s.push_back(input);
        }
	solve.groupAnagrams(s);
	return 0;
}
