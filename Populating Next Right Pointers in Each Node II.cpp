/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// O(n)空间
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
// O(1)空间
//解题思路：
//与上一题类似，唯一的不同是每次要先找到一个第一个有效的next链接节点，并且递归的时候要先处理右子树，再处理左子树。


[Code]
1:    void connect(TreeLinkNode *root) {  
2:      // Start typing your C/C++ solution below  
3:      // DO NOT write int main() function  
4:      if(root== NULL) return;  
5:      TreeLinkNode* p = root->next;  
6:      while(p!=NULL)  
7:      {  
8:         if(p->left!=NULL)  
9:         {  
10:            p = p->left;  
11:            break;  
12:        }  
13:        if(p->right!=NULL)  
14:        {  
15:           p = p->right;  
16:           break;  
17:        }  
18:        p = p->next;  
19:      }  
20:      if(root->right!= NULL)  
21:      {        
22:        root->right->next = p;  
23:      }  
24:      if(root->left !=NULL)  
25:      {        
26:        root->left->next = root->right? root->right:p;        
27:      }  
28:      connect(root->right);  
29:      connect(root->left);      
30:    }  
