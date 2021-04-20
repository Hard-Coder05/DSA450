//TLE SOLUTION
//
//
//
//
//
//
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int curri = n - 1;
        int count = 0;
        while (curri != 0)
        {
            for (int i = 0; i < curri; i++)
            {
                if (arr[i] >= curri - i)
                {
                    curri = i;
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends