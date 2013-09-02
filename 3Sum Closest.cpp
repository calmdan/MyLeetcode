//O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min=INT_MAX;
        int res=INT_MAX;
        int n = num.size();
        sort(num.begin(),num.end());
        for(int i=0;i<=n-3;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            int l =i+1,r=n-1;
            while(l<r)
            {
                int s = num[i]+num[l]+num[r];
                if(s == target) return s;
                else if(s >target) r--;
                else l++;
                int t = abs(target - s);
                if( t <min) 
                {
                    res = s;
                    min = t;
                }
            }
        }
        return res;
    }
};
