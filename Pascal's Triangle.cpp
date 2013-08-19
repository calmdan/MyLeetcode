class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        for(int i=0;i<numRows;i++)
        {
            vector<int > t(i+1,1);
            for(int j=1;j<i;j++)
            {
                if(i==0) continue;
                t[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(t);
        }
        return res;
    }
};
