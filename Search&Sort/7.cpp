
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int rep;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (++mp[arr[i]] == 2)
                rep = arr[i];
        }
        int i = 0;
        int *ans = new int(2);
        ans[0] = rep;
        for (int i = 0; i < n; i++)
            if (mp[i + 1] == 0)
            {
                ans[1] = i + 1;
                break;
            }
        return ans;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends