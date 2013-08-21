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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return check(root->left,root->right);
    }
    bool check(TreeNode * l,TreeNode * r)
    {
        if(l==NULL && r ==NULL) return true;
        if(l!=NULL && r !=NULL) 
        {
            if(l->val !=r->val) return false;
            return check(l->left,r->right)&&check(l->right,r->left);
        }
        return false;    
    }
};
