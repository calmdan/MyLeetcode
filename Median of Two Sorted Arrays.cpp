//============================================================================
// There are two sorted arrays A and B of size m and n respectively. Find the
// median of the two sorted arrays. The overall run time complexity should be
// O(log (m+n)).
//============================================================================

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays1(A, m, B, n);
    //O(m+n)
    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = -1, m2 = -1;
        int s = (m + n) / 2;
        while (s >= 0) {
            int a = (i < m) ? A[i] : INT_MAX;
            int b = (j < n) ? B[j] : INT_MAX;
            m1 = m2;
            if (a < b) {
                m2 = a;
                i++;
            }
            else {
                m2 = b;
                j++;
            }
            s--;
        }
        if ((m + n) % 2 == 0) return (m1 + m2) / 2.0;
        return m2;
    };
    //O(log(m+n))
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        return findMedianHelper2(A, m, B, n, max(0, (m-n)/2), min(m-1, (m+n)/2));
    };

    double findMedianHelper2(const int A[], const int m, const int B[], const int n, const int l, const int r) {
        if (l > r) return findMedianHelper2(B, n, A, m, max(0, (n-m)/2), min(n-1, (m+n)/2));
        int i = (l+r)/2;
        int j = (m+n)/2-i;

        assert(i >= 0 && i <= m && j >= 0 && j <= n);
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        int Ai = ((i == m) ? INT_MAX : A[i]);
        int Bj = ((j == n) ? INT_MAX : B[j]);

        if (Ai < Bj_1) return findMedianHelper2(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedianHelper2(A, m, B, n, l, i-1);

        if (((m+n) % 2) == 1) return A[i];
        return (max(Ai_1, Bj_1) + Ai) / 2.0;
    };
};


//k-th number of two sorted arrays
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = n + m;
        
        if (total % 2 == 0) {
            return (findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
        }
        else 
            return findKth(A, m, B, n, total / 2 + 1);
    }
    
    double findKth(int a[], int m, int b[], int n, int k) {
        if (m > n) return findKth(b, n, a, m, k);
        if (m == 0) return b[k-1];
        if (k == 1) return min(a[0], b[0]);
        
        int ia = min(k/2, m);
        int ib = k - ia;
        if (a[ia-1] < b[ib-1]) return findKth(a+ia, m - ia, b, n, k - ia);
        else  if (a[ia-1] > b[ib-1]) return findKth(a, m, b+ib, n - ib, k - ib);
        else return a[ia-1];
    }
};

//best solution
double MedianOfFour (int a, int b, int c, int d)
{
        int minValue = min (d, min (a, min (b,c) ) );
        int maxValue = max (d, max (a, max (b,c) ) );
        return (a + b + c + d - minValue - maxValue) / 2.0 ;
}
 
double MedianOfThree (int a, int b, int c)
{
        int minValue = min (a, min (b,c) ) ;
        int maxValue = max (a, max (b,c) ) ;
        return (a + b + c - minValue - maxValue);
}
 
//constraint : n <= m
double MedianSortedArrays (int A[MAX], int n, int B[MAX], int m)
{
        //base case # 1
        if ( n == 1 ) 
        {
                if ( m == 1 ) 
                        return (A[0] + B[0]) / 2.0; 
                if ( m % 2 == 1) 
                         return ( B[m/2] + MedianOfThree (A[0], B[m/2-1], B[m/2+1]) ) / 2.0 ;
                else 
                        return MedianOfThree ( A[0], B[m/2-1], B[m/2] );
        }
 
        //base case # 2
        if ( n == 2 ) 
        {
                if ( m == 2 )
                        return MedianOfFour (A[0], A[1], B[0], B[1]);
                if ( m % 2 == 1 )
                        return MedianOfThree ( B[m/2], min(A[0], B[m/2+1]), max (A[1], B[m/2-1]) ) ;
                else 
                        return MedianOfFour ( B[m/2-1], B[m/2], min(A[0], B[m/2+1]), max(A[1], B[m/2-2]) );
        }
 
 
        int minRemoved, idxA = n/2 , idxB = m/2 ;
 
        if ( A[idxA] < B[idxB]  )                                               
        {
                if ( n % 2 == 0 ) --idxA;       //for even number of elements --idxA points to lower median of A[]
                minRemoved = min ( idxA, m - idxB - 1) ;        
                return MedianSortedArrays ( A + minRemoved, n - minRemoved, B, m - minRemoved); 
        }
        else                                                                                    
        {
                if ( m % 2 == 0 ) --idxB;       //for even number of elements --idxB points to lower median of B[]
                minRemoved = min ( n - idxA - 1, idxB) ;        
                return MedianSortedArrays ( A, n - minRemoved, B + minRemoved, m - minRemoved); 
        }
 
}


//my solution
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0) return n%2==0?(B[(n-1)/2]+B[(n-1)/2+1])/2.0:B[(n-1)/2];
        if(n==0) return m%2==0?(A[(m-1)/2]+A[(m-1)/2+1])/2.0:A[(m-1)/2];
        if(m>=n) return findRec(A,m,B,n);
        return findRec(B,n,A,m);
    }
    double MedianOfFour (int a, int b, int c, int d)
    {
        int minValue = min (d, min (a, min (b,c) ) );
        int maxValue = max (d, max (a, max (b,c) ) );
        return (a + b + c + d - minValue - maxValue) / 2.0 ;
    }

    double MedianOfThree (int a, int b, int c)
    {
        int minValue = min (a, min (b,c) ) ;
        int maxValue = max (a, max (b,c) ) ;
        return (a + b + c - minValue - maxValue);
    }
    double findRec(int A[], int m, int B[], int n)
    {
        if(n==1)
        {
            if(m==1) return (A[0]+B[0])/2.0;
            if(m%2==0) return MedianOfThree(B[0],A[(m-1)/2],A[(m-1)/2+1]);
            else return MedianOfFour(B[0],A[(m-1)/2],A[(m-1)/2+1],A[(m-1)/2-1]);
        }
        else if(n==2)
        {
            if(m==2) return MedianOfFour(A[0],A[1],B[0],B[1]);
            else if(m%2==0) return MedianOfFour(A[(m-1)/2],A[(m-1)/2+1],max(A[(m-1)/2-1],B[0]),min(A[(m-1)/2+2],B[1]));
            else return MedianOfThree(A[(m-1)/2],max(A[(m-1)/2-1],B[0]),min(A[(m-1)/2+1],B[1]));
        }
        double m1 = A[(m-1)/2];
        double m2 = B[(n-1)/2];
        if(m1==m2)
        {
            if(m%2==0 && n%2==0)
            {
                double t1 = A[(m-1)/2+1];
                double t2 = B[(n-1)/2+1];
                return t1>t2?(m1+t2)/2:(m1+t1)/2;
            }
            else return m1;
        }
        else if(m1>m2)
        {
            return findRec(A,m-(n-1)/2,B+(n-1)/2,n-(n-1)/2);
        }
        else
        {
            return findRec(A+(n-1)/2,m-(n-1)/2,B,n-(n-1)/2);
        }
    }
};
