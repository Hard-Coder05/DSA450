#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int n, long long int k)
{
    queue<long long int> pq;
    long long int i = 0, j = 0;
    vector<long long> ans;
    while (j < n)
    {
        if (A[j] < 0)
            pq.push(A[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (pq.empty())
                ans.push_back(0);
            else
                ans.push_back(pq.front());
            if (A[i] < 0)
                pq.pop();
            j++;
            i++;
        }
    }
    return ans;
}