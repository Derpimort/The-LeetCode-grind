#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution {
public:
    
    //Copied from LC.... god tier solution
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
        if (idx >= preorder.size() || preorder[idx] > p_val)
            return nullptr;
        auto n = new TreeNode(preorder[idx++]);
        n->left = bstFromPreorder(preorder, n->val);
        n->right = bstFromPreorder(preorder, p_val);
        return n;
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
    cout<<endl;
    return 0;
}
