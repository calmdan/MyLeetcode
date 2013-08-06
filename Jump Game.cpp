class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0 || n==1) return true;
        int reach=0;
        int i=0;
        while(i<n-1 && i<=reach)
        {
            reach = max(reach,i+A[i]);
            if(reach>=n-1) return true;
            i++;
        }
        return false;
    }
};
