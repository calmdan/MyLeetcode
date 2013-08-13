class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0 || n==1) return 0;
        int old_reach=0;
        int new_reach=0;
        int res=0;
        int i=0;
        while(i<n-1 && i<=new_reach)
        {
            if(i>old_reach)
            {
                res++;
                old_reach = new_reach;
            }
            new_reach = max(new_reach,i+A[i]);
            if(new_reach>=n-1) return res+1;
            i++;
        }
        return -1;
    }
};
