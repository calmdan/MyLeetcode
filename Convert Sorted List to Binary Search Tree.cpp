/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        int n=0;
        ListNode *p = head;
        while(p)
        {
            p=p->next;
            n++;
        }
        if(n==1) 
        {
            TreeNode * root = new TreeNode(head->val);
            return root;
        }
        int mid = n/2;
        p = head;
        int i=1;
        while(i<mid)
        {
            p=p->next;
            i++;
        }
        ListNode * r = p->next->next;
        TreeNode * root = new TreeNode(p->next->val);
        p->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(r);
        return root;
    }
};

//bottom up的解法，顺着list的顺序把叶子节点赋给他们的parent
