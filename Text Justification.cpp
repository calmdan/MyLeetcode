class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if(L==0 || L==1) return words;
        int n = words.size();
        int sum=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(sum+words[i].length()+c <=L)
            {
                if(i==n-1)
                {
                    string s;
                    while(c>0)
                    {
                        s += words[i-c];
                        s.append(1,' ');
                        c--;
                    }
                    s+= words[i];
                    s.append(L-s.length(),' ');
                    res.push_back(s);
                }
                c++;
                sum +=words[i].length();
            }
            else
            {
                int t = L -sum;
                if(c==1)
                {
                    string s;
                    s += words[i-c];
                    s.append(L-words[i-c].length(),' ');
                    res.push_back(s);
                    sum=c=0;
                    i--;
                    continue;
                }
                int x = t%(c-1);
                int y = t/(c-1);
                string s;
                while(c>0)
                {
                    s += words[i-c];
                    if(c!=1)s.append(y,' ');
                    if(x>0)
                    {
                        s.push_back(' ');
                        x--;
                    }
                    c--;
                }
                res.push_back(s);
                sum=c=0;
                i--;
            }
        }
        return res;
    }
};
