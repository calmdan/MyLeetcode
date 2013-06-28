string roman[][10] = {
    {"", "I","II","III","IV","V","VI","VII","VIII","IX"},
    {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"", "M","MM","MMM","  "," ","  ","   ","    ","  "},
    {"", "", "","","","","","","",""}
};
class Solution {
public:

    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string result;
        int m=1, d=1;
        while(m<num)
        {
            m *=10;
            d++;
        }
        while(m>0)
        {
            result.append(roman[--d][num/m]);
            num = num % m;
            m = m/10;
        }
        return result;
    }
};
