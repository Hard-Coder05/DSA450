#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int sum[n];
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x;
        cin >> x;
        int i = upper_bound(arr, arr + n, x) - arr;
        cout << i << " " << sum[i - 1] << endl;
    }
}
