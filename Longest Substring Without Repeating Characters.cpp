class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<int> substr;
        bool visited[26];
        int maxlen = 0;
        
        for(int i=0; i<26; i++)
        {
            visited[i] = false;
        }
        for(int i = 0; i< s.length(); i++)
        {
            
            if(visited[s[i]-'a'])
            {
                while(substr.front() != s[i])
                {
                    visited[substr.front() - 'a'] = false;
                    substr.pop();
                }
                substr.pop();
                substr.push(s[i]);
            }
            else
            {
                visited[s[i]-'a'] = true;
                substr.push(s[i]);
            }
            maxlen = max(maxlen, (int)substr.size());
        }
        return maxlen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str;
        vector<bool> v(26,false);
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(v[s[i]-'a'])
            {
                while(str[0]!=s[i])
                {
                    v[str[0]-'a']=false;
                    str.erase(0,1);
                }
                str.erase(0,1);
            }
            str +=s[i];
            v[s[i]-'a'] = true;
            res = max(res,int(str.length()));
        }
        return res;
    }
};
