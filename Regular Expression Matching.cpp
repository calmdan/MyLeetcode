class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
    assert(s && p);
    if (*p == '\0') return *s == '\0';

    // next char is not '*': must match current character
    if (*(p+1) != '*') {
        assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }
    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p+2)) return true;
        s++;
    }
    return isMatch(s, p+2);
    }
};
