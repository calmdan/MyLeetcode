const static string dic[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(digits.length()==0)
        {
            vector<string> result;
            result.push_back(string(""));
            return result;
        }
        return CombinationsRecusive(digits,0,digits.size());
    }
    vector<string> CombinationsRecusive(string digits, int p, int size)
    {
        vector<string> result;
        if(p==size) return result;
        string pre = dic[digits[p]-'0'];
        vector<string> prefix;
        int len1 = pre.length();
        for(int i=0;i<len1;i++)
        {
            prefix.push_back(string(1,pre[i]));
        }
        vector<string> suffix = CombinationsRecusive(digits,p+1,size);
        int len2= suffix.size();
        if(len2 == 0)
        {
            for(int i=0;i<len1;i++)
            {
                result.push_back(prefix[i]);
            }
        }
        else
        {
            for(int i=0;i<len1;i++)
            {
                for(int j=0;j<len2;j++)
                    result.push_back(prefix[i]+suffix[j]);
            }
        }
        return result;
    }
};
