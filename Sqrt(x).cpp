class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x==0 || x==1) return x;
        
        int l = 0;
        int r = x;
        while(l<=r)
        {
            int mid = (r-l)/2+l;
            if(x/mid ==mid) return mid;
            else if(x/mid <mid) r=mid -1;
            else l = mid +1;
        }
        return r;
    }
};
