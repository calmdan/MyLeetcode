/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //O(n)空间，中序遍历，保存节点指针和值，把值排序后重新复制一遍
 //不考虑栈空间的O(1)空间，修改中序遍历，找到两个节点，交换
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode * pre = NULL;
        TreeNode * m1=NULL, *m2=NULL;
        inorder(root,pre,m1,m2);
        int temp = m1->val;
        m1->val = m2->val;
        m2->val = temp;
        return;
    }
    bool inorder(TreeNode *root,TreeNode * &pre,TreeNode * &m1,TreeNode *&m2)
    {
        if(root == NULL ) return false;
        inorder(root->left,pre,m1,m2);
        if(pre!=NULL && root->val < pre->val)
        {
            if(!m1)
            {
                m1 = pre;
            }
            m2 = root;          
        }
        pre = root;
        inorder(root->right,pre,m1,m2);
    }
};
//O(1)空间不能用栈或者递归中序遍历，用Morris Traversal(利用线索二叉树（threaded binary tree）)
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
       void recoverTree(TreeNode *root) {
        TreeNode *f1, *f2;
        bool found = false;
        TreeNode *pre, *par = 0; // previous AND parent
        while(root) { // Morris Traversal
            if(root->left == 0) {
                if(par && par->val > root->val) {  // inorder previous is: par
                    if(!found) {
                        f1 = par;
                        found = true;
                    }
                    f2 = root;
                }
                par = root;
                root = root->right;
                continue;
            }
            pre = root->left;
            while(pre->right != 0 && pre->right != root) 
                pre = pre->right;
            if(pre->right == 0) {
                pre->right = root;
                root = root->left;
            } else {
                pre->right = 0;
                if(pre->val > root->val) { // inorder previous is: pre
                    if(!found) {
                        f1 = pre;
                        found =true;
                    }
                    f2 = root;
                }
                par = root;
                root = root->right;
            }
        }
        if(found)
            swap(f1->val, f2->val);
    }
};
