class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int start = INT_MIN;
        int end = INT_MIN;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            vector<int> v;
            if (start == INT_MIN)
                start = intervals[i][0];
            if (end == INT_MIN)
                end = intervals[i][1];
            if (end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
            }
            else
            {
                end = max(end, intervals[i][1]);
                v.push_back(start);
                v.push_back(end);
                ans.push_back(v);
                start = INT_MIN;
                end = INT_MIN;
            }
        }
        if (start == INT_MIN)
        {
            ans.push_back(intervals[n - 1]);
        }
        else
        {
            vector<int> v;
            v.push_back(start);
            v.push_back(end);
            ans.push_back(v);
        }
        return ans;
    }
};