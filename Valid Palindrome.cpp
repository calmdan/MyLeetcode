class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<s.length();)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))i++;
            else if((s[i]>='a' && s[i]<='z')) 
            {
                s[i] = s[i]-('a'-'A');
                i++;
            }
            else s.erase(s.begin()+i);
        }
        if(s.empty()) return true;
        int l = 0;
        int r = s.length()-1;
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else break;
        }
        return l>r;
    }
};
