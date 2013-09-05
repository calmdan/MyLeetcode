class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res=INT_MIN;
        int cur=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(cur<0) cur = A[i];
            else cur += A[i];
            res = max (res,cur);
        }
        return res;
    }
};


class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n,INT_MIN);
        dp[0]=A[0];
        int max=dp[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]<0) dp[i]=A[i];
            else dp[i]=dp[i-1]+A[i];
            if(max<dp[i]) max = dp[i];
        }
        return max;
    }
};


但是题目中要求，不要用这个O(n)解法，而是采用Divide & Conquer。这就暗示了，解法必然是二分。分析如下：

假设数组A[left, right]存在最大值区间[i, j](i>=left & j<=right)，以mid = (left + right)/2 分界，无非以下三种情况：

subarray A[i,..j] is
(1) Entirely in A[low,mid-1]
(2) Entirely in A[mid+1,high]
(3) Across mid
对于(1) and (2)，直接递归求解即可，对于(3)，则需要以min为中心，向左及向右扫描求最大值，意味着在A[left, Mid]区间中找出A[i..mid], 而在A[mid+1, right]中找出A[mid+1..j]，两者加和即为(3)的解。

代码实现如下：
1:    int maxSubArray(int A[], int n) {  
2:      // Start typing your C/C++ solution below  
3:      // DO NOT write int main() function  
4:      int maxV = INT_MIN;  
5:      return maxArray(A, 0, n-1, maxV);      
6:    }  
7:    int maxArray(int A[], int left, int right, int& maxV)  
8:    {  
9:      if(left>right)  
10:        return INT_MIN;  
11:      int mid = (left+right)/2;  
12:      int lmax = maxArray(A, left, mid -1, maxV);  
13:      int rmax = maxArray(A, mid + 1, right, maxV);  
14:      maxV = max(maxV, lmax);  
15:      maxV = max(maxV, rmax);  
16:      int sum = 0, mlmax = 0;  
17:      for(int i= mid -1; i>=left; i--)  
18:      {  
19:        sum += A[i];  
20:        if(sum > mlmax)  
21:          mlmax = sum;  
22:      }  
23:      sum = 0; int mrmax = 0;  
24:      for(int i = mid +1; i<=right; i++)  
25:      {  
26:        sum += A[i];  
27:        if(sum > mrmax)  
28:          mrmax = sum;  
29:      }  
30:      maxV = max(maxV, mlmax + mrmax + A[mid]);  
31:      return maxV;  
32:    }  
