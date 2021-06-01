#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n);
        map<int, int> mp;
        mp[A[0]]++;
        for (int i = 1; i < n - 1; i++)
        {
            int curr = A[i];
            for (int j = i + 1; j < n; j++)
            {
                if (mp[X - (curr + A[j])] > 0)
                    return true;
            }
            mp[A[i]]++;
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends