class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(),num.end());
        int size = num.size();
        if(size<4) return result;//!!!!
        int flag1=num[0]-1;//!!!!
        int flag2=num[0]-1;
        int flag3=num[0]-1;
        for(int i = 0; i < size - 3; i++)//!!!!
        {
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j = i+1;j<size -2;j++)
            {
                if(j>i+1 && num[j]==num[j-1]) continue;
                int l = j+1;
                int r = size -1;
                while(l<r)
                {
                    int s = num[i]+num[j]+num[l]+num[r];
                    if(s>target) r--;
                    else if(s<target)l++;
                    else if(num[j]!=flag1 || num[l]!=flag2  || num[r]!=flag3)//!!!!
                    {
                        vector<int> t;
                        t.push_back(num[i]);
                        t.push_back(num[j]);
                        t.push_back(num[l]);
                        t.push_back(num[r]);
                        result.push_back(t); 
                        flag1= num[j];
                        flag2= num[l];
                        flag3 = num[r];
                        l++,r--;
                    }
                    else 
                    {
                        l++,r--;
                    }
                }
            }
        }
        return result;
    }
};
