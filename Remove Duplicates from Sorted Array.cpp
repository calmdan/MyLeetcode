class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return n; //take care for the boundry!!!
        int len = 0;
        for(int i=1;i<n;i++)
        {
            if(A[i]!=A[len]) A[++len] = A[i];
        }
        return len+1;
    }
};
