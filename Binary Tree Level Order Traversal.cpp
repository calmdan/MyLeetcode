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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >  res;
        if(root==NULL) return res;
        queue<TreeNode> q;
        q.push(*root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> t;
            while(n>0)
            {
                TreeNode tmp = q.front();
                q.pop();
                t.push_back(tmp.val);
                if(tmp.left!=NULL) q.push(*tmp.left);
                if(tmp.right!=NULL) q.push(*tmp.right);
                n--;
            }
            res.push_back(t);
        }
        return res;
    }
};
