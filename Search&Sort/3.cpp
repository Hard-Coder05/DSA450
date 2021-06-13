//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>, int);

//User code will be pasted here

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
            cin >> vec[i];

        int target;
        cin >> target;

        cout << Search(vec, target) << "\n";
    }
} // } Driver Code Ends

//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find
int Search(vector<int> arr, int k)
{
    int start = 0, end = arr.size() - 1;
    int min = arr[0];
    int index = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < min)
        {
            min = arr[mid];
            index = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (arr[0] <= k && index != 0)
    {
        int l = 0, r = index - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == k)
                return mid;
            if (arr[mid] > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    else
    {
        int l = index, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == k)
                return mid;
            if (arr[mid] > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    return -1;
}