class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n<=1) return 0;
        int maxp=0;
        int low= prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<low)
            {
                low = prices[i];
            }
            maxp = max(maxp,prices[i]-low);
        }
        return maxp;
    }
};
