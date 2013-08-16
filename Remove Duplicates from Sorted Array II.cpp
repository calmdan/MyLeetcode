class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=2) return n;
        int p=0,count=1;
        for(int i=1;i<n;i++)
        {
            if(A[i]==A[p])
            {
                if(count==2) continue;
                else
                {
                    count++;
                    A[++p]=A[i];
                }
            }
            else 
            {
                A[++p]=A[i];
                count = 1;
            }
        }
        return p+1;
    }
};
