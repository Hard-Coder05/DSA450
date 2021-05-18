#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        int index = 1;
        int curr = 1;
        while (curr < N)
        {
            index++;
            curr = curr << 1;
        }
        if (curr == N)
            return index;
        else
            return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends