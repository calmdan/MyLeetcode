class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i=0,reach =0;
        while(i<=reach)
        {
            reach = max(reach, i+A[i]);
            if(reach>=n-1) return true;
            i++;
        }
        return false;
    }
};
