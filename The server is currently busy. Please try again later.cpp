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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        int l = getH(root->left);
        int r = getH(root->right);
        if(abs(l-r)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int getH(TreeNode *root)
    {
        if(!root) return 0;
        return max(getH(root->left),getH(root->right))+1;
    }
};

//更好的方法，isBalanced不用递归检查左右，直接在高度中记录
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        int l = getH(root->left);
        int r = getH(root->right);
        if(l<0 || r<0 ||abs(l-r)>1) return false;
        return true;
    }
    int getH(TreeNode *root)
    {
        if(!root) return 0;
        int l = getH(root->left);
        int r = getH(root->right);
        if(l<0 || r<0 ||abs(l-r)>1) return -1;
        return max(l,r)+1;
    }
};
