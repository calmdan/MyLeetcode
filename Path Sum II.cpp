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
    vector<vector<int> > result;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> ans;
        func(root,sum,ans);
        return result;
    }
    void func(TreeNode *root, int sum,vector<int> v)
    {
        if(root==NULL) return;
        else if(root->left==NULL && root->right==NULL && root->val==sum) 
        {
            v.push_back(root->val);
            result.push_back(v);
            return;
        }
        else 
        {
            v.push_back(root->val);
            func(root->left, sum-root->val,v);
            func(root->right,sum-root->val,v);
            return;
        }
    }
};
