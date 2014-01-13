/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //假设数字范围不会达到上下界 MIN,MAX
 //如果假设不成立，可以为函数一个参数，表示只检查上界、只检查下界，都检查三种情况
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root,INT_MIN,INT_MAX);
        
    }
    bool check(TreeNode *root,int lb,int ub)
    {
        if(root ==NULL) return true;
        if(root->val <=lb || root->val >=ub) return false;
        if( !check(root->left,lb,root->val) )return false;
        if( !check(root->right,root->val,ub) )return false;
        return true;
    }
    
};



class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root,INT_MIN,INT_MAX,0);
        
    }
    bool check(TreeNode *root,int lb,int ub,int flag)
    {
        if(root ==NULL) return true;
        if(flag==0)
        {
            if( !check(root->left,lb,root->val,2) )return false;
            if( !check(root->right,root->val,ub,1) )return false;
        }
        else if(flag==1)
        {
            if(root->val <=lb ) return false;
            if( !check(root->left,lb,root->val,3) )return false;
            if( !check(root->right,root->val,ub,1) )return false;
        }
        else if(flag==2)
        {
            if( root->val >=ub) return false;
            if( !check(root->left,lb,root->val,2) )return false;
            if( !check(root->right,root->val,ub,3) )return false;
        }
        else
        {
            if(root->val <=lb || root->val >=ub) return false;
            if( !check(root->left,lb,root->val,3) )return false;
            if( !check(root->right,root->val,ub,3) )return false;
        }
        return true;
    }
    
};
