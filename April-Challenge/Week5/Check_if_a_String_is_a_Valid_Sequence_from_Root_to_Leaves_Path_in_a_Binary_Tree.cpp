//LC recursion
//Couldn't check, LC private-d it.
class Solution{
public:
    bool isValidSequence(TreeNode* root, vector<int>& a, int ind=0){
        if(ind>=a.size())
            return false;
        else if(root=NULL)
            return false;
        else if((root->left==NULL && root->right==NULL) && (root->val==a[ind] && root->val==a.back()))
            return false;

        return (ind<a.size() && (root->val==a[ind] && (isValidSequence(root->left, a, ind+1)|| isValidSequence(root->right, a, ind+1))));

    }
}
