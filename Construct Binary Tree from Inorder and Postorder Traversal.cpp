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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    return buildRec(postorder,inorder,0,postorder.size(),0,inorder.size());
    }
    TreeNode * buildRec(vector<int> &postorder, vector<int> &inorder,
    int postl,int postr,int inl, int inr)
    {
        int n = postr-postl;
        if(n==0) return NULL;
        TreeNode * root= new TreeNode(postorder[postr-1]);
        if(n==1) return root;
        int i=inl;
        for(;i<inr;i++)
        {
            if(inorder[i]==root->val) break;
        }
        root->left = buildRec(postorder,inorder,postl,postl+i-inl,inl,i);
        root->right = buildRec(postorder,inorder,postl+i-inl,postr-1,i+1,inr);
        return root;
    }
};
