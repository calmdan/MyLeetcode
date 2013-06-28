class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearchRotate(A,0,n-1,target);
    }
    int bsearchRotate(int A[],int l,int r, int t)
    {
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        if(t == A[mid]) return mid;
        else if(t>A[mid])
        {
            if(A[r] >=A[mid] && t >A[r]) return bsearchRotate(A,l,mid-1,t);
            else return bsearchRotate(A,mid+1,r,t);
        }
        else
        {
            if(A[l] <=A[mid] && t < A[l]) return bsearchRotate(A,mid+1,r,t);
            else  return bsearchRotate(A,l,mid-1,t);
        }
    }
};
