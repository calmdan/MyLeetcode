/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //迭代方式怎么写？？
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        inorder(res,root);
        return res;        
    }
    void inorder(vector<int> &res,TreeNode *root)
    {
        if(root==NULL) return;
        inorder(res,root->left);
        res.push_back(root->val);
        inorder(res,root->right);
    }
};
