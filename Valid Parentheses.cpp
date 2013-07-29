class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stack;
        int size = s.length();
        for(int i=0;i<size;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stack.push(s[i]);
            else if(s[i]==')')
            {
                if(!stack.empty() && stack.top()=='(') stack.pop();
                else return false;
            }
            else if(s[i]==']')
            {
                if(!stack.empty() && stack.top()=='[') stack.pop();
                else return false;
            }
            else if(s[i]=='}')
            {
                if(!stack.empty() && stack.top()=='{') stack.pop();
                else return false;
            }
        }
        return stack.empty();
    }
};
