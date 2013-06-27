class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearch(A,0,n-1,target);
    }
    int bsearch(int A[],int l, int r, int t)
    {
        if(l>r)
        {
            return l;// l is always the index to insert
        }
        int mid = r+(l-r)/2;
        if(A[mid] == t)
        {
            return mid;
        }
        else if(A[mid] > t)
        {
            return bsearch(A,l,mid-1,t);
        }
        else
        {
            return bsearch(A,mid+1,r,t);
        }
        
    }
};
