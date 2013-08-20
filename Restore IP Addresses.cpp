class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        func(res,s,0,0,"");
        return res;        
    }
    void func(vector<string> &res,string &s,int i, int dep,string t)
    {
        if(dep==4 && i ==s.length())
        {
            t.resize(t.length()-1);
            res.push_back(t);
            return;
        }
        if(i>s.length()) return;
        int n= s.length()-i;
        if(n>3*(4-dep)) return;
        if(n<4-dep) return;
        int num=0;
        int ii = i;
        while(ii<s.length() && ii-i<=2)
        {
            num = num*10 + s[ii]-'0';
            ii++;
            if(num <=255)  func(res,s,ii,dep+1,t+s.substr(i,ii-i)+'.');
            if(num==0) break;
        }          
    }
};
