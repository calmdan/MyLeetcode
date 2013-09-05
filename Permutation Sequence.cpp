//直接枚举，列出第k个，超时
/*One straightforward solution would be to call the next_permutation and count the calling times, 
but it is not necessary to do the actual permutation, we just need to find out which digit in which position.
Here is the idea. For each k, divide the number of previous permutations into some factorials, 
for each factorial, count how many and save this info into an index array. 
Based on this array, we can choose which digit at each position. e.g, for n=4, k=20, it has 19 permutations before, 
19 = 3*3! + 0*2! + 1*1! + 0, so the index[] would be 0,1,0,3 (reversing order), which can be interpreted as the order 
of digit in an ordered array, e.g, 3 means arr[3] in [1,2,3,4] which is 4.*/


class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> fact(n+1,0);
        fact[0]=1;
        for(int i=1;i<n;i++)
        {
            fact[i]=fact[i-1]*i;
        }
        vector<int> index(n,0);
        int kk = k-1;
        for(int i=n-1;i>=0;i--)
        {
            while(kk>=fact[i])
            {
                index[i]++;
                kk -=fact[i];
            }
        }
        vector<int> a;
        for(int i=0;i<n;i++) a.push_back(i+1);
        string res;
        for(int i=n-1;i>=0;i--)
        {
            res += char(a[index[i]]+'0');
            a.erase(a.begin()+index[i]);
        }
        return res;
    }
};
