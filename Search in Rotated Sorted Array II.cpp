class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0,r=n-1;
        while(l<=r)
        {
            int m = (r-l)/2+l;
            if(target == A[m]) return true;
            if(A[l]<A[m])//左边的顺序仍然是对的
            {
                if(target<A[m] && target >=A[l]) r=m-1;
                else l = m+1;
            }
            else if(A[l]>A[m])//右边的顺序仍然是对的
            {
                if(target>A[m] && target <=A[r]) l=m+1;
                else r = m-1;
            }
            else l++;
        }
        return false;
    }
};
