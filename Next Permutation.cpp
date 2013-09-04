class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if(n==1) return;
        int i =n-2;
        for(;i>=0;i--)
        {
            if(num[i]<num[i+1]) break;
        }
        if(i==-1) 
        {
            reverse(num.begin(),num.end());
            return;
        }
        int j=i+1;
        for(;j<n;j++)
        {
            if(num[j]<=num[i]) break;
        }
        j--;
        swap(num[i],num[j]);
        reverse(num.begin()+i+1,num.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        auto it = num.end()-1;
        while(it!=num.begin() && *(it-1)>=*it) it--;//find *(it-1) < *it
        if(it ==num.begin())
        {
            reverse(num.begin(),num.end());
            return;
        }
        it--;//left elem to be exchanged
        auto rit = it+1;
        while(rit!=num.end() && *rit >*it) rit++;
        rit--;//right elem to be exchanged
        //swap (left,right), then reverse right part to ascending order
        iter_swap(it,rit);
        reverse(it+1,num.end());
    }
};
