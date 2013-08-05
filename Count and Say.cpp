class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return "";
        if(n==1) return "1";
        int k=1;
        string res("1");
        
        while(k++<n)
        {
            string tmp(res);
            res.clear();
            int i=0;
            int len = tmp.length();
            int num=1;
            while(i<len)
            {
                if(tmp[i+1] ==tmp[i]) num++;
                else
                {
                    res+=char(num+'0');
                    res+=tmp[i];
                    num=1;
                }
                i++;
            }
        }
        return res;
    }
};
