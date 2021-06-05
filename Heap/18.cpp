//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{

    string summing(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 && j >= 0)
        {
            int x = a[i] - '0';
            int y = b[j] - '0';
            int cal = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            ans = to_string(cal) + ans;
            i--;
            j--;
        }
        while (i >= 0)
        {
            int x = a[i] - '0';
            int cal = (x + carry) % 10;
            carry = (x + carry) / 10;
            ans = to_string(cal) + ans;
            i--;
        }
        while (j >= 0)
        {
            int y = b[j] - '0';
            int cal = (y + carry) % 10;
            carry = (y + carry) / 10;
            ans = to_string(cal) + ans;
            j--;
        }
        if (carry != 0)
            ans = to_string(carry) + ans;

        for (int i = 0; i < ans.size(); i++)
            if (ans[i] != '0')
                return ans.substr(i);

        return "0";
    }

public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        string a, b;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                a += to_string(arr[i]);
            else
                b += to_string(arr[i]);
        }

        return summing(a, b);
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends