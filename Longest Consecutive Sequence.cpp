class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, bool> map;
        for(int i=0;i<num.size();i++)
        {
            map[num[i]]=true;
        }
        int res =0;
        for(int i=0;i<num.size();i++)
        {
            if(map[num[i]])
            {
                res = max(res,find(map,num[i]));
            }
        }
        return res;
    }
    int find(unordered_map<int, bool> &map,int n)
    {
        map[n]=false;
        int res=1;
        if(map[n+1])
        {
            res = max(res,res+ find(map,n+1));
        }
        if(map[n-1])
        {
            res = max(res,res+ find(map,n-1));
        }
        return res;
    }
};
