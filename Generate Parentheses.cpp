class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if(n==0) return res;
        generate(res,"",0,n,0,0);
        return res;
    }
    void generate(vector<string>& res,string s, int dep,int n, int lnum,int rnum)
    {
        if(dep==2*n) 
        {
            res.push_back(s);
            return;
        }
        if(lnum<n)
        {
            generate(res,s+"(",dep+1,n,lnum+1,rnum);
        }
        if(rnum < lnum)
        {
            generate(res,s+")",dep+1,n,lnum,rnum+1);
        }
    }
};
