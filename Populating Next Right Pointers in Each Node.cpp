/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //迭代宽搜
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n>0)
            {
                TreeLinkNode* tmp = q.front();
                q.pop();
                if(n==1) tmp->next = NULL;
                else tmp->next = q.front();
                if(tmp->left!=NULL) q.push(tmp->left);
                if(tmp->right!=NULL) q.push(tmp->right);
                n--;
            }
        }
    }
};

//简洁递归，只对完美二叉树试用
void connect(TreeLinkNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root || (!root->left && !root->right))
        return;
    root->left->next = root->right;
    if (root->next) 
        root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);
}
