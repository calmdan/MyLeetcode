//use strlen, start from end to begin,直观
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        int i = len-1;
        int res=0;
        bool found =false;
        while(i>=0)
        {
            if(s[i]==' ')
            {
                if(found==false) 
                {
                    i--;
                    continue;
                }
                else break;
            }
            else
            {
                found = true;
                i--;
                res++;
            }
        }
        return res;
    }
};

//start from to begin to end，代码简洁巧妙
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        int res = 0;
        while(*s)
        {
            if(*(s++)!=' ')
            {
                res++;
            }
            else if(*s && *s!=' ') res=0;
        }
        return res;
    }
};
