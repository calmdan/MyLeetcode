class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<string> s;
        for(int i=0;i<path.length();i++)
        {
            if(path[i]=='/') continue;
            if(path[i]=='.')
            {
                if(i+1==path.length()) continue;
                if(i+1!=path.length() && path[i+1]=='/') continue;
                if(i+1!=path.length() && path[i+1]=='.') 
                {
                    if(s.empty()) continue;
                    else s.pop();
                }
                else 
                {
                    int tmp=i;
                    while(i<path.length()&&path[i]!='/') i++;
                    s.push(path.substr(tmp,i-tmp));
                }
            }
            else
            {
                int tmp=i;
                while(i<path.length()&&path[i]!='/') i++;
                s.push(path.substr(tmp,i-tmp));
            }
        }
        string res;
        if(s.empty()) return "/";
        stack<string> ss; 
        while(!s.empty())
        {
            ss.push(s.top());
            s.pop();
        }
        while(!ss.empty())
        {
            res+='/';
            res+=ss.top();
            ss.pop();
        }
        return res;
    }
};
