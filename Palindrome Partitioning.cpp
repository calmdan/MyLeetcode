class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i=0;i<len;i++)
        {
            dp[i][i]=true;
        }
        for(int i=len-2;i>=0;i--)
        {
            dp[i][i+1] = s[i]==s[i+1];
            for(int j=i+2;j<len;j++)
            {
                dp[i][j]= s[i]==s[j] && dp[i+1][j-1];
            }
        }
        return patiRec(dp,0,s);
    }
    vector<vector<string>> patiRec(vector<vector<bool>> &dp, int start,string s)
    {
        vector<vector<string>> res;
        if(start == s.length())
        {
            res.push_back(vector<string>());
            return res;
        }
        for(int i=start;i<s.length();i++)
        {
            if(dp[start][i])
            {
                vector<vector<string>> tmp = patiRec(dp,i+1,s);
                for(int j=0;j<tmp.size();j++)
                {
                    tmp[j].insert(tmp[j].begin(),s.substr(start,i-start+1));
                    res.push_back(tmp[j]);
                }
            }
        }
        return res;
    }
};
