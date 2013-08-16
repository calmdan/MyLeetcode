class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0,r=n-1,k=0;
        while(k<=r)
        {
            if(A[k]==0)
            {
                swap(A[k++],A[l++]);//why also k++? because l's next position can only be white （因为2都移到末尾去了！！）
            }
            else if(A[k]==2)
            {
                swap(A[k],A[r--]);
            }
            else k++;
        }
    }
};
