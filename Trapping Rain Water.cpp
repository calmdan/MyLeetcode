class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> height(n,0);
        int maxh=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>maxh) maxh = A[i];
            height[i]=maxh;
        }
        maxh=0;
        for(int i=n-1;i>=0;i--)
        {
            if(A[i]>maxh) maxh = A[i];
            height[i]=min(maxh,height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=height[i]-A[i];
        }
        return sum;
    }
};
