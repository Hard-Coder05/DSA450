//SUCCESFUL SUBMISSION
//
//
//
//
//
//

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        long long int max = 1;
        long long int min = 1000000000000;
        for (int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            if (max < x)
                max = x;
            if (min > x)
                min = x;
        }
        cout << min << " " << max << endl;
    }
    return 0;
}

//TLE but bubble sort type approach
//
//
//
//
//
//
//
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] < 0)
            {
                int curr = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < 0)
                        break;
                    swap(arr[curr], arr[j]);
                    curr++;
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.segregateElements(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends