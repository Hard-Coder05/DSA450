

// } Driver Code Ends

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int i = 0, j = 0;
        while (j < n)
        {
            pq.push(make_pair(arr[j], j));
            if (j - i + 1 < k)
                j++;
            else
            {
                while (pq.top().second < i)
                    pq.pop();
                ans.push_back(pq.top().first);
                i++;
                j++;
            }
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

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends