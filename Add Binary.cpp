//朴素想法
class Solution {
public:
    const int scale = 2;
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res;
        int len1 = a.length()-1;
        int len2 = b.length()-1;
        int c=0;
        while(len1>=0 && len2>=0)
        {
            int s = a[len1]-'0'+b[len2]-'0'+c;
            c = s/scale;
            if(s<scale) res += char('0'+s);
            else
            {
                s = s % scale;
                res += char('0'+s);
            }
            len1--;
            len2--;
        }
        while(len1>=0)
        {
            int s = a[len1]-'0'+c;
            c = s/scale;
            if(s<scale) res += char('0'+s);
            else
            {
                s = s % scale;
                res += char('0'+s);
            }
            len1--;
        }
        while(len2>=0)
        {
            int s = b[len2]-'0'+c;
            c = s/scale;
            if(s<scale) res += char('0'+s);
            else
            {
                s = s % scale;
                res += char('0'+s);
            }
            len2--;
        }
        if(c==1) res += char('0'+c);
        reverse(res.begin(), res.end());
        return res;
    }
};
//更简洁的代码
//学会利用string类、vector类等的insert, +等方法在string前面加如字符。 STL!!!!!!!!!!!!
//摆脱大整数加法乘法只用数组
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int sum = 0;
        int i = a.size() - 1, j = b.size() - 1;
        int a_val = 0, b_val = 0;
        while (i >= 0 || j >= 0 || carry) {
            a_val = (i >= 0 ? a[i] - '0' : 0);
            b_val = (j >= 0 ? b[j] - '0' : 0);

            sum = a_val + b_val + carry;
            carry = sum / 2;
            sum %= 2;
            res.insert(0, 1, sum + '0');

            i = (i >= 0 ? -- i : i);
            j = (j >= 0 ? -- j : j);
        }
        return res;
    }
};
