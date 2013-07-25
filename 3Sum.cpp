class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(),num.end());
        int size = num.size();
        if(size<3) return result;//!!!!
        int flag_l=num[0]-1;//!!!!
        int flag_r=num[0]-1;
        for(int i = 0; i < size - 2 && num[i]<=0; i++)//!!!!
        {
            if(i>0 && num[i]==num[i-1]) continue;
            int l = i+1;
            int r = size -1;
            while(l<r)
            {
                int s = num[i]+num[l]+num[r];
                if(s>0) r--;
                else if(s<0)l++;
                else if(num[l]!=flag_l  || num[r]!=flag_r)//!!!!
                {
                    vector<int> t;
                    t.push_back(num[i]);
                    t.push_back(num[l]);
                    t.push_back(num[r]);
                    result.push_back(t); 
                    flag_l = num[l];
                    flag_r = num[r];
                    l++,r--;
                }
                else 
                {
                    l++,r--;
                }
            }
        }
        return result;
    }
};
