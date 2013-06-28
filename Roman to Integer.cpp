class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i =0;
        int size = s.length();
        int result = 0;
        for(int i=0;i<size;i++)
        {
            if((i+1)<size && m[s[i]]<m[s[i+1]])
            {
                result += m[s[i+1]] - m[s[i]];
                i++;
            }
            else
            {
                result +=m[s[i]];
            }
        }
        return result;
    }
};
