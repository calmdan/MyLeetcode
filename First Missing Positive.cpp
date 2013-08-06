//O(n)时间复杂度需要记录每个数字是否出现，还要求常量空间复杂度有点难
//想到用输入数组本身！！！！！！！！！！！！
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;
        if(n==0) return 1;
        while(i<n)
        {
            if(A[i] >0 && A[i]<=n)
            {
                if(A[i] != i+1 && A[A[i]-1] != A[i])
                {
                    swap(A[i],A[A[i]-1]);
                }
                else i++;
            }
            else i++;
        }
        int j=0;
        while(j<n)
        {
            if(A[j] != j+1) return j+1;
            else j++;
        }
        return j+1;
    }
};
