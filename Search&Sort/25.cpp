// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to find minimum number of pages
    bool isValid(int arr[], int n, int m, int maxP)
    {
        int student = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > maxP)
            {
                student++;
                sum = arr[i];
            }
            if (student > m)
                return false;
        }
        return true;
    }
    int findPages(int arr[], int n, int m)
    {
        if (n < m)
            return -1;
        int total_sum = 0, maxEle = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            total_sum += arr[i];
            maxEle = max(arr[i], maxEle);
        }
        int l = maxEle, r = total_sum;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValid(arr, n, m, mid) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends