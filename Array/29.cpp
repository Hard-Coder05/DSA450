#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (maxi < arr[i])
            {
                maxi = arr[i];
                index = i;
            }
        }
        maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i <= index; i++)
        {
            if (maxi < arr[i])
            {
                maxi = arr[i];
                continue;
            }
            ans += maxi - arr[i];
        }
        maxi = INT_MIN;
        for (int i = n - 1; i >= index; i--)
        {
            if (maxi < arr[i])
            {
                maxi = arr[i];
                continue;
            }
            ans += maxi - arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends