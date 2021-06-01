// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

// Driver code
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends

int minSwap(int *arr, int n, int k)
{

    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++;
    //cout<<count<<endl;
    int cc = 0, j = 0, i = 0, ans = count;

    while (j < n)
    {
        if (arr[j] <= k)
            cc++;
        if (j - i + 1 == count)
        {
            ans = min(ans, count - cc);
            if (arr[i] <= k)
                cc--;
            i++;
        }
        j++;
    }

    return ans;
}
