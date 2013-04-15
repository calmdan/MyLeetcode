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
