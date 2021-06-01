class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        int profit = 0;
        int arr[n - 1];

        int maxi = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i] = max(maxi, prices[i + 1]);
            maxi = arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            profit = max(profit, arr[i] - prices[i]);
        }
        return profit;
    }
};