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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode *> q;
        bool lr = true;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> t;
            if(lr)
            {
                lr = false;
                for(int i=0;i<n;i++)
                {
                    TreeNode * tt =  q.front();
                    q.pop();
                    t.push_back(tt->val);
                    if(tt->left) q.push(tt->left);
                    if(tt->right) q.push(tt->right);
                }
            }
            else
            {
                lr=true;
                stack<int> s;
                for(int i=0;i<n;i++)
                {
                    TreeNode * tt =  q.front();
                    q.pop();
                    s.push(tt->val);
                    if(tt->left) q.push(tt->left);
                    if(tt->right) q.push(tt->right);
                }
                while(!s.empty())
                {
                    t.push_back(s.top());
                    s.pop();
                }
            }
            res.push_back(t);
        }
        return res;
    }
};
