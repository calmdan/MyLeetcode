//brute force, O(n*m)
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        if(len2==0) return haystack;
        for(int i=0;i<len1-len2+1;i++)
        {
            char *p1 = haystack+i;
            char *p2 = needle;
            int num=0;
            while(*p1!='\0'&& *p2!='\0' && *p1 ==*p2)
            {
                p1++;
                p2++;
                num++;
            }
            if(num==len2) return haystack+i;
        }
        return NULL;
    }
};
