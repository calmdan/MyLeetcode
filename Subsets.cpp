class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res;
        vector<int> tmp;
        sort(S.begin(),S.end());
        func(res,S,0,tmp);
        return res;
    }
    void func(vector<vector<int> > &res,vector<int> &S,int index, vector<int> & tmp)
    {
        if(index ==S.size()) 
        {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(S[index]);
        func(res,S,index+1,tmp);
        tmp.pop_back();
        func(res,S,index+1,tmp);
    }
};

//在之前的基础上加上新的数
vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > v(1);
    for(int i = 0; i < S.size(); ++i) {
        int j = v.size();
        while(j-- > 0) {
            v.push_back(v[j]);
            v.back().push_back(S[i]);
        }
    }
    return v;
}
