//O(n^3)
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(),num.end());
        int size = num.size();
        if(size<4) return result;//!!!!
        int flag1=num[0]-1;//!!!!
        int flag2=num[0]-1;
        int flag3=num[0]-1;
        for(int i = 0; i < size - 3; i++)//!!!!
        {
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j = i+1;j<size -2;j++)
            {
                if(j>i+1 && num[j]==num[j-1]) continue;
                int l = j+1;
                int r = size -1;
                while(l<r)
                {
                    int s = num[i]+num[j]+num[l]+num[r];
                    if(s>target) r--;
                    else if(s<target)l++;
                    else if(num[j]!=flag1 || num[l]!=flag2  || num[r]!=flag3)//!!!!
                    {
                        vector<int> t;
                        t.push_back(num[i]);
                        t.push_back(num[j]);
                        t.push_back(num[l]);
                        t.push_back(num[r]);
                        result.push_back(t); 
                        flag1= num[j];
                        flag2= num[l];
                        flag3 = num[r];
                        l++,r--;
                    }
                    else 
                    {
                        l++,r--;
                    }
                }
            }
        }
        return result;
    }
};
//如果不要求去重和排序输出，只求找出这四个数
//有O(n^2）解法
#include <stdio.h>
#include <stdlib.h>
 
// The following structure is needed to store pair sums in aux[]
struct pairSum
{
    int first; // index (int A[]) of first element in pair
    int sec; // index of second element in pair
    int sum;  // sum of the pair
};
 
// Following function is needed for library function qsort()
int compare (const void *a, const void * b)
{
    return ( (*(pairSum *)a).sum - (*(pairSum*)b).sum );
}
 
// Function to check if two given pairs have any common element or not
bool noCommon(struct pairSum a, struct pairSum b)
{
    if (a.first == b.first || a.first == b.sec ||
            a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}
 
 
// The function finds four elements with given sum X
void findFourElements (int arr[], int n, int X)
{
    int i, j;
 
    // Create an auxiliary array to store all pair sums
    int size = (n*(n-1))/2;
    struct pairSum aux[size];
 
    /* Generate all possible pairs from A[] and store sums
       of all possible pairs in aux[] */
    int k = 0;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }
 
    // Sort the aux[] array using library function for sorting
    qsort (aux, size, sizeof(aux[0]), compare);
 
    // Now start two index variables from two corners of array
    // and move them toward each other.
    i = 0;
    j = size-1;
    while (i < size && j >=0 )
    {
        if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j]))
        {
            printf ("%d, %d, %d, %d\n", arr[aux[i].first], arr[aux[i].sec],
                                     arr[aux[j].first], arr[aux[j].sec]);
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}
 
// Driver program to test above function
int main()
{
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    findFourElements (arr, n, X);
    return 0;
}
