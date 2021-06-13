#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long x)
    {
        sort(arr, arr + n);
        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int a = arr[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (a + arr[j] + arr[k] >= x)
                    k--;
                else
                {
                    count += (k - j);
                    j++;
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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends