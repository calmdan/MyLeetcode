/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //迭代方式怎么写？？用栈模拟
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        inorder(res,root);
        return res;        
    }
    void inorder(vector<int> &res,TreeNode *root)
    {
        if(root==NULL) return;
        inorder(res,root->left);
        res.push_back(root->val);
        inorder(res,root->right);
    }
};


void in_order_traversal_iterative(BinaryTree *root) {
    stack<BinaryTree*> s;
    BinaryTree *current = root;
    bool done = false;
    while (!done) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            if (s.empty()) {
                done = true;
            } else {
                current = s.top();
                s.pop();
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

