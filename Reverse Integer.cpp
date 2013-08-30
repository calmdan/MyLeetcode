/*If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
*/
class Solution {
public:
        int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lastDigit = 0;
        int result = 0;
        bool isNeg = x>0? false:true;
        x = abs(x);
    
        while(x>0)
        {
            lastDigit = x%10;
            result = result*10 + lastDigit;
            x = x/10;
        }
    
        if(result<0) return -1;//判断溢出
    
        if(isNeg)
            result *=-1;
    
        return result;        
    }
};
