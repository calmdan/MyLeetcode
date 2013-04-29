class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int max = 2*(nRows-1);
        string res;
        //不考虑的话会MLE
        if(nRows==1)
        {
            return s;
        }
        for(int i=0;i<nRows;i++)
        {
            if(i==0 || i ==nRows-1)
            {
                for(int j=i;j<s.length();j=j+max)
                {
                     res +=s[j];
                }
            }

            else
            {
                int k=max - 2*i;
                for(int j=i;j<s.length();)
                {
                    res+=s[j];
                    j=j+k;
                    k=max -k;
                }
            }
        }
        return res;
    }
};
