class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(1,0);
        if(n==0) return res;
        int m = 1<<n;
        for(int i=1;i<m;i++)
        {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};

//递归方法
public ArrayList<Integer> grayCode(int n) {  
    ArrayList<Integer> resultList = new ArrayList<Integer>();
    if (n <= 1) {
        resultList.add(0);
        if (n == 1) resultList.add(1);
        return resultList;
    }

    ArrayList<Integer> prevList = grayCode(n - 1);
    int highest_bit = 1 << (n - 1);
    for (int i = prevList.size() - 1; i >= 0; i--) {
        resultList.add(prevList.get(i) + highest_bit);
    }

    prevList.addAll(resultList);
    return prevList;
}
