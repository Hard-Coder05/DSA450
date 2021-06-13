#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimumNumberOfSwaps(string chars)
    {
        int swap = 0, imbalance = 0;
        int countLeft = 0, countRight = 0;
        for (int i = 0; i < chars.length(); i++)
        {
            if (chars[i] == '[')
            {
                countLeft++;

                if (imbalance > 0)
                {
                    swap += imbalance;
                    imbalance--;
                }
            }
            else if (chars[i] == ']')
            {
                countRight++;
                imbalance = (countRight - countLeft);
            }
        }
        return swap;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
} // } Driver Code Ends