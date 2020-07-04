#include<iostream>
#include<vector>

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
    int getDiameter(TreeNode *root, int& height) 
    { 
      int lh=0,rh=0,ld=0, rd=0; 
        
      if(root == NULL) 
      { 
         height = 0; 
         return 0;
      } 
      ld = getDiameter(root->left, lh); 
      rd = getDiameter(root->right, rh); 
      height = max(lh, rh) + 1; 
      return max(lh + rh, max(ld, rd)); 
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        return getDiameter(root, h);
    }
};

int main(){
    return 1;
}
