class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n<=1) return 0;
        int sum=0;
        int low= prices[0], up=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<up)
            {
                sum+=up-low;
                low =up= prices[i];
            }
            if(prices[i]>up)
            {
                up = prices[i];
            }
        }
        sum+=up-low;
        return sum;
    }
};
