
// Simple Recursion
class Solution {
public:
    int max;
    Solution():max(INT_MIN){}

    int recur(TreeNode* node){
         if(node == NULL)
            return 0;
        int left = std::max(0, recur(node->left));
        int right = std::max(0, recur(node->right));
        max = std::max(max, left+right+node->val);
        return std::max(left, right)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return max;
    }
};
