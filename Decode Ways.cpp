//递归打表实现
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())return 0;
        vector<int> dp(s.length()+1,-1);
        return work(s,dp,0);
    }
    int work(string &s,vector<int> &dp, int i)
    {
        if(dp[i] !=-1) return dp[i];
        if(i==s.length()) 
        {
            dp[i]=1;
            return dp[i];
        }
        if(i==s.length()-1 && s[i]!='0')
        {
            dp[i]=1;
            return dp[i];
        }
        if(s[i]=='0')
        {
            dp[i]=0;
            return dp[i];
        }
        if(s[i]>='3' && s[i]<='9') 
        {
            dp[i]= work(s,dp,i+1);
            return dp[i];
        }
        if(s[i]=='1') 
        {
            if(s[i+1]=='0') 
            {
                dp[i]=work(s,dp,i+2);  
            }
            else dp[i]= work(s,dp,i+1)+work(s,dp,i+2);
            return dp[i];
        }
        if(s[i]=='2') 
        {
            if(s[i+1]=='0' || (s[i+1]>='7'&&s[i+1]<='9')) 
            {
                dp[i]=work(s,dp,i+2);  
            } 
            else dp[i]= work(s,dp,i+1)+work(s,dp,i+2);
            return dp[i];
        }
    }
};


//迭代实现，从前向后
class Solution {
public:
    int numDecodings(string s) {
      int n = s.size();
      if (n == 0)
        return 0;
      int c[n];
      c[0] = 1;
      for(int i = 1; i <= n; i++ ) {
        int c1 = 0;
        if (s[i-1] != '0')
          c1 = c[i-1];
        int c2 = 0;
        if (i >= 2 && (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <='6'))
            c2 = c[i-2];
        c[i] = c1 + c2;
      }
      return c[n];
    }
};
