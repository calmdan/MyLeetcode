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
//        return findMedianSortedArrays1(A, m, B, n);
        return findMedianSortedArrays1(A, m, B, n);
    }
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
