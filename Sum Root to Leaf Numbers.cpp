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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return func(root,0);
    }
    int func(TreeNode * n,int s)
    {
        if(n== NULL) return 0;
        if(n->left ==NULL && n->right == NULL) 
        {
            return s*10+n->val;
        }
        return func(n->left,s*10+n->val)+func(n->right,s*10+n->val);
    }
};


//use class member variable
class Solution {
public:
    int result;
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result =0;
        if(root ==NULL) return 0;
        func(root,0);
        return result;
    }
    void func(TreeNode * n,int s)
    {

        if(n->left ==NULL && n->right == NULL) 
        {
            result += s*10+n->val;
            return;
        }
        if(n->left !=NULL) 
        {
            func(n->left,s*10+n->val);
        }
        if(n->right !=NULL) 
        {
            func(n->right,s*10+n->val);
        }
    }
};
