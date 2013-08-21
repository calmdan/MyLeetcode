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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildRec(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode * buildRec(vector<int> &preorder, vector<int> &inorder,
    int prel,int prer,int inl, int inr)
    {
        int n = prer-prel;
        if(n==0) return NULL;
        TreeNode * root= new TreeNode(preorder[prel]);
        if(n==1) return root;
        int i=inl;
        for(;i<inr;i++)
        {
            if(inorder[i]==root->val) break;
        }
        root->left = buildRec(preorder,inorder,prel+1,prel+i-inl+1,inl,i);
        root->right = buildRec(preorder,inorder,prel+i-inl+1,prer,i+1,inr);
        return root;
    }
};
