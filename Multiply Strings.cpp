//用大整数加法
class Solution {
public:
    const int scale = 10;
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
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.length();
        int len2 = num2.length();
        string res;
        for(int i=len1-1;i>=0;i--)
        {
            string tmp;
            int k=0;
            while(k++<len1-1-i) tmp.insert(0,1,'0');
            int c = 0;
            for(int j=len2-1;j>=0;j--)
            {
                int num = (num1[i]-'0')*(num2[j]-'0')+c;
                int digit = num%10;
                c = num/10;
                tmp.insert(0,1,digit+'0');
            }
            if(c!=0) tmp.insert(0,1,c+'0');
            tmp.erase(0,tmp.find_first_not_of('0'));
            if(tmp.empty()) tmp +='0';
            res = addBinary(res,tmp);
        }
        return res;
    }
};
//i和j相乘放在i+j+1位上，不需要大整数加法
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0'||num2[0]=='0') return "0";
        int n1(num1.size()), n2(num2.size()), n(n1+n2);
        vector<int> r(n,0);
        string      s(n,'0');
        for(size_t i=0;i<n1;++i){
            for(size_t j=0;j<n2;++j){
                r[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(size_t i=n-1;i>0;--i){
            if(r[i]>9)  r[i-1]+=r[i]/10;
            s[i]  += r[i]%10;
        }
        s[0]+=r[0];
        return s[0]=='0'?string(s.begin()+1,s.end()):s;
    }
};
