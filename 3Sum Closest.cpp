//直观解法，效率不高，对每个target枚举
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        sort(num.begin(),num.end());
        int size = num.size();
        int n=0;
        while(true)
        {
            int flag[2]={-1,1};
            for(int j=0;j<2;j++)
            {
                int t=target;
                if(n!=0) t =target+n*flag[j];
                for(int i = 0; i < size - 2; i++)//!!!!
                {
        
                    int l = i+1;
                    int r = size -1;
                    while(l<r)
                    {
                        int s = num[i]+num[l]+num[r];
                        if(s>t) r--;
                        else if(s<t)l++;
                        else
                        {
                            return t;
                        }
                    }
                }
            }
            n++;
        }
    }
};


//O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int n = num.size();
        int cl = num[0]+num[1]+num.back();
        int sum;
        for(int i=0;i<n-2;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
                sum = num[i]+num[j]+num[k];
                if(abs(sum-target)<abs(cl-target))  cl=sum;
                if(sum==target)                     return target;
                if(sum<target){
                        sum = num[i]+num[++j]+num[k];
                }
                else{
                        sum = num[i]+num[j]+num[--k];
                }
            }
        }
        return cl;
    }
};
