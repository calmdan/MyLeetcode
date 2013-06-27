class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearch(A,0,n-1,target);
    }
    vector<int> bsearch(int A[],int l, int r, int target)
    {
        vector<int> result;
        if(l>r) 
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int mid = (l+r)/2;
        if(A[mid]==target)
        {
            int x=mid-1, y =mid+1;
            while(x>=l)
            {
                if(A[x]!=target)break;
                x--;
            }
            while(y<=r)
            {
                if(A[y]!=target)break;
                y++;
            }
            result.push_back(x+1);
            result.push_back(y-1);
            return result;
        }
        else if(A[mid]>target)
        {
            return bsearch(A,l,mid-1,target);
        }
        else return bsearch(A,mid+1,r,target);
    }
    
};
