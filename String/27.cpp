class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 1)
            return strs[0];
        string ans = "";
        string comparator = strs[0];
        int m = comparator.length();
        for (int i = 0; i < m; i++)
        {
            char curr = comparator[i];
            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] != curr)
                    return ans;
            }
            ans += curr;
        }
        return ans;
    }
};