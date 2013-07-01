class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1, j = n-1;
        int t = m+n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]>B[j]) A[t--] = A[i--];
            else A[t--] = B[j--];
        }
        if(j>=0)
        {
            while(t>=0)
            {
                A[t--] = B[j--];
            }
        }
    }
};
