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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        rec(root);
    }
    TreeNode * rec(TreeNode *root)
    {
        if(!root->left) 
        {
            if(!root->right) return root;
            return rec(root->right);
        }
        TreeNode * t1 = root->right;
        root->right = root->left;
        TreeNode * t2 = rec(root->left);
        root->left = NULL;
        if(!t1) return t2;
        t2->right = t1;
        return rec(root->right);
    }
};

class Solution {
public:
void flatten(TreeNode *root) {
    if (!root) return;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    if (left) {
        root->right = left;
        root->left = NULL;

        TreeNode* rightmost = left;
        while(rightmost->right) {rightmost = rightmost->right;}
        rightmost->right = right; // point the right most to the original right child
    }

    flatten(root->right);        
}
};
