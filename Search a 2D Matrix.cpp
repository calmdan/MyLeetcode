class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        int row = mybSearch(matrix,target,0,m-1);
        if(row==-1) return false;
        else if(row==m) return true;
        else
        {
            return binary_search(matrix[row].begin(),matrix[row].end(),target);
        }
    }
    //return: 0~m-1,第0~m-1行；-1，没有；m，找到了
    int mybSearch(vector<vector<int> > &matrix, int target, int l,int r)
    {
        if(r-l==0) return l;
        if(r-l==1)
        {
            if(target == matrix[r][0]) return matrix.size();
            else if(target > matrix[r][0]) return r;
            else return l;
        }
        if(target < matrix[l][0]) return -1;
        if(target > matrix[r][0]) return r;
        int mid = (r-l)/2+l;
        if(target < matrix[mid][0]) return mybSearch(matrix,target,l,mid-1);
        else if(target >matrix[mid][0]) return mybSearch(matrix,target,mid,r);
        else return  matrix.size();
    }
};
//更简洁的方法：
//把二维数组看成一维的，直接二分查找。。。。
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid/cols][mid%cols] == target)
                return true;
            else if (matrix[mid/cols][mid%cols] < target)
                low = mid + 1;
            else if (matrix[mid/cols][mid%cols] > target)
                high = mid - 1;
        }
        return false;
    }
};
