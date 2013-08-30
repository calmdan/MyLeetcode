class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        bool valid = false;
        bool isNegative = false;
        const char *p = str;
        //空格
        while(*p++==' ');
        p--;
        //正负号
        if(*p=='-')
        {
            isNegative = true;
            p++;
        }
        else  if(*p=='+')
        {
            isNegative = false;
            p++;
        }
        long long result = 0;
        
        while(*p!='\0')
        {
            int digit = *p-'0';
            if(digit<0 || digit >10) break;//出现字符后跳出循环
            else valid =true;
            if(result >INT_MAX/10)//判断溢出
            {
                if(isNegative)
                    result =INT_MIN;
                else result = INT_MAX;
                return result;
            }
            if(result == INT_MAX/10 && digit>=8)//判断溢出
            {
                if(isNegative)
                    result =INT_MIN;
                else result = INT_MAX;
                return result;
            }
            result = result*10 +digit;
            p++;
        }
        if(valid == false) result=0;
        else
        {
            result = isNegative?result*(-1):result;
        }
        return result;
    }
};
