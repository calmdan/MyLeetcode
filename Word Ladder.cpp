//开始想歪了，想到DP去了
//其实是明显的BFS
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;
        int len = start.length();
        unordered_set<string> add;
        add.insert(start);
        q.push(start);
        int ret=1;
        while(!q.empty())
        {
            int n = q.size();
            ret++;
            for(int i=0;i<n;i++)
            {
                string s = q.front();
                q.pop();
                for(int j=0;j<len;j++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        string tmp = s;
                        if(tmp[j]==c) continue;
                        tmp[j]=c;
                        if(tmp==end) return ret;
                        if(dict.find(tmp)!=dict.end() && add.find(tmp)==add.end())
                        {
                            add.insert(tmp);
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
