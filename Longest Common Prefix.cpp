class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(strs.size() == 0) return "";// Don't forget!!!!
        
        int num = strs.size();
        int len = strs[0].length();
        for(int i =0;i<len;i++)
        {
            for(int j=1;j<num;j++)
            {
                if(strs[j][i]!= strs[0][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
