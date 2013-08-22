class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n<=1) return 0;
        vector<int> pre(n,0);
        vector<int> post(n,0);
        int low = prices[0];
        for(int i=1;i<n;i++)
        {
            low = min(low,prices[i]);
            pre[i] = max(pre[i-1],prices[i]-low);
        }
        int up = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            up = max(up,prices[i]);
            post[i] = max(post[i+1],up-prices[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res = max(res,pre[i]+post[i]);
        }
        return res;
    }
};
//扩展到m次选择，解释见discuss
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int f[3] = {0};
            int g[3] = {0};

            int n = prices.size() - 1;
            for (int i = 0; i < n; ++i) {
                int diff = prices[i+1] - prices[i];
                int m = min(i+1, 2);
                for (int j = m; j >= 1; --j) {
                    f[j] = max(f[j], g[j-1]) + diff;
                    g[j] = max(g[j], f[j]);
                }
            }
            return max(g[1], g[2]);
        }
    };
