/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxs=INT_MIN;
        int ret = maxrec(root,maxs);
        return max(ret,maxs);
    }
    int maxrec(TreeNode *root, int & maxsum)
    {
        if(root==NULL) return 0;
        int retl = maxrec(root->left,maxsum);
        int retr = maxrec(root->right,maxsum);
        int ret = max(root->val,max(retl+root->val,retr+root->val));
        maxsum = max(maxsum,max(ret,retl+retr+root->val));
        return ret;
    }
};
