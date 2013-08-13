//题目要找的是：通过颠倒字符得到的字符串组，数量大于一才算

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string,vector<string>> dict;
        vector<string> res;
        for(int i=0;i<strs.size();i++)
        {
            string key = strs[i];
            sort(key.begin(),key.end());
            if(dict.find(key)==dict.end())
            {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                dict[key]=tmp;
            }
            else 
            {
                dict[key].push_back(strs[i]);
            }
        }
        for(auto i=dict.begin();i!=dict.end();i++)
        {
            if((*i).second.size()>1)
            {
                for(auto j=i->second.begin();j!=i->second.end();j++) res.push_back(*j);
            }
        }
        return res;
    }

};
