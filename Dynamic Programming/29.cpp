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
        if (arr[0] == 0)
            return -1;
        for (int i = 0; i < curri; i++)
        {
            if (arr[i] >= curri - i)
            {
                curri = i;
                count++;
                i = -1;
            }
            if (curri == 0)
                break;
        }
        if (curri > 0)
            return -1;
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