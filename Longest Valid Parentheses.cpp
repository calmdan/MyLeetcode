class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=0;
        int cur=0;
        stack<int> st;
        int last = -1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(st.empty()) last=i;
                else 
                {
                    st.pop();
                    if(st.empty()) max = std::max(max,i-last);
                    else max = std::max(max,i-st.top());
                }
            }
            else 
            {  
                st.push(i);
            }
        }
        return max;
    }
};
