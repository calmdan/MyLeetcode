class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(rowIndex+1,1);
        vector<int> temp(rowIndex+1,1);
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=1;j<i;j++)
            {
                res[j]=temp[j-1]+temp[j];
            }
            temp.assign(res.begin(),res.end());
        }
        return res;
    }
};
