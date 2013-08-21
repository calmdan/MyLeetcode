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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1,n);
    }
    vector<TreeNode *> generate(int s, int e)
    {
        vector<TreeNode *> res;   
        if(s > e) 
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=s;i<=e;i++)
        {
            //TreeNode * root = new TreeNode(i);  not here!!!!!!!!!!!
            vector<TreeNode *>  l  = generate(s,i-1);
            vector<TreeNode *>  r  = generate(i+1,e);
            for(auto x=l.begin();x!=l.end();x++)
            {
                for(auto y=r.begin();y!=r.end();y++)
                {
                    TreeNode * root = new TreeNode(i);// for eachr l and r, create a root, or else just change the value
                    root->left = *x;
                    root->right = *y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
