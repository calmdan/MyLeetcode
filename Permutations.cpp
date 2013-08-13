class Solution {
public:
    vector<bool> used;
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        used.resize(num.size(),false);
        vector<vector<int>> res;
        vector<int> tmp;
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
            if(used[i]==false)
            {
                tmp.push_back(num[i]);
                used[i]=true;
                work(res, num,tmp);
                tmp.pop_back();
                used[i]=false;
            }
        }
        return;
    }
};
