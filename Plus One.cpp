class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c=1;
        int i = digits.size()-1;
        while(i>=0)
        {
            int s = c+digits[i];
            c = s/10;
            int num = s % 10;
            digits[i] = num;
            i--;
        }
        if(c) digits.insert(digits.begin(),1,1);
        return digits;
    }
};
