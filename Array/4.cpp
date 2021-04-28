#include <bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

void sort012(int arr[], int n)
{
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
        else
            two++;
    }
    int i = 0;
    for (; i < zero; i++)
        arr[i] = 0;
    for (; i < one + zero; i++)
        arr[i] = 1;
    for (; i < one + zero + two; i++)
        arr[i] = 2;
}