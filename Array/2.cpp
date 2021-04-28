// T.C. : O(n)
// Linear Search : Do Comparison and get the result
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