//各种情况
// -1E+2
// 1.
//前后空格，中间的空格， 利用string的erase和find_first_not_of find_last_not_of来trim
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str(s);
        str.erase(0, str.find_first_not_of(" /n"));
        str.erase(str.find_last_not_of(' ') + 1);
        if(str.size()==0) return false;
        if(str.find_first_of("abcdfghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ")!= -1) return false;
        if(str.find_first_of("1234567890")== -1) return false;
        bool digit = false;
        bool e = false;
        bool dot = false;
        bool sign = false;
        bool needdigit = false;
        bool first = true;
        int i=0;
        while(i<str.length())
        {
            if(str[i]=='+' || str[i]=='-')
            {
                if(!first) return false;
                if(sign == true) return false;
                sign = true;
            }
            if(str[i]==' ')
            {
                return false;
            }               
            if(isdigit(str[i]))
            {
                digit = true;
                if(needdigit) needdigit = false;
                first = false;
            }
            if(str[i]=='.')
            {
                if(dot ==true || e==true)
                {
                    return false;
                }
                else
                {
                    dot = true;
                    first = false;
                };
            }
            if(str[i]=='e' ||str[i]=='E')
            {
                if(digit==false || e ==true)
                {
                    return false;
                }
                else
                {
                    e = true;
                    first =true;
                    sign = false;
                    needdigit = true;
                };
            }
            i++;
        }
        if(needdigit) return false;
        return true;
    }
};
