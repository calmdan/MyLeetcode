//思想：递归在每个位置选择数字放置时，对于重复的数字只放置一次
//具体实现：先排序，当前数字跟前一个数字相同且用过，就跳过当前的数字

class Solution {
public:
    vector<bool> used;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        used.resize(num.size(),false);
        vector<vector<int>> res;
        vector<int> tmp;
        sort(num.begin(),num.end());
        work(res, num,tmp);
        return res;
    }
    void work(vector<vector<int> > &res,vector<int> &num,vector<int> tmp)
    {
        if(tmp.size()==num.size()) 
        {
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(used[i] || i>0 && num[i]==num[i-1] && used[i-1]) continue;
            tmp.push_back(num[i]);
            used[i]=true;
            work(res, num,tmp);
            tmp.pop_back();
            used[i]=false;
        }
        return;
    }

};
