#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findMin(int arr[], int n)
    {
        int start = 0, end = n - 1;
        int min = arr[0];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] < min)
            {
                min = arr[mid];
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return min;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends