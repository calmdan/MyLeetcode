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



    void connect(TreeLinkNode *root) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      if(root== NULL) return;  
      TreeLinkNode* p = root->next;  
      while(p!=NULL)  
      {  
         if(p->left!=NULL)  
         {  
            p = p->left;  
            break;  
        }  
        if(p->right!=NULL)  
        {  
           p = p->right;  
           break;  
        }  
        p = p->next;  
      }  
      if(root->right!= NULL)  
      {        
        root->right->next = p;  
      }  
      if(root->left !=NULL)  
      {        
        root->left->next = root->right? root->right:p;        
      }  
      connect(root->right);  //!!!!
      connect(root->left);      
    }  
