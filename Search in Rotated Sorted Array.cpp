//第二版，思路更清晰，循环
//关键点：旋转之后两部分仍然各自有序
//找到有序的那一半，在范围内就进去找，否则在另外一半找
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0,r=n-1;
        while(l<=r)
        {
            int m = (r-l)/2+l;
            if(target == A[m]) return m;
            if(A[l]<A[m])//左边的顺序仍然是对的
            {
                if(target<A[m] && target >=A[l]) r=m-1;
                else l = m+1;
            }
            else if(A[l]>A[m])//右边的顺序仍然是对的
            {
                if(target>A[m] && target <=A[r]) l=m+1;
                else r = m-1;
            }
            else l++;
        }
        return -1;
    }
};


//第一版，递归
//未考虑有重复元素的情况，边界考虑的有问题，但是能AC
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearchRotate(A,0,n-1,target);
    }
    int bsearchRotate(int A[],int l,int r, int t)
    {
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        if(t == A[mid]) return mid;
        else if(t>A[mid])
        {
            if(A[r] >=A[mid] && t >A[r]) return bsearchRotate(A,l,mid-1,t);
            else return bsearchRotate(A,mid+1,r,t);
        }
        else
        {
            if(A[l] <=A[mid] && t < A[l]) return bsearchRotate(A,mid+1,r,t);
            else  return bsearchRotate(A,l,mid-1,t);
        }
    }
};
