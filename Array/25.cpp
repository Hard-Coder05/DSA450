class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (auto &i : nums)
            mp[i]++;
        vector<int> ans;
        int k = floor((float)(n / 3));
        for (auto &i : mp)
            if (i.second > k)
                ans.push_back(i.first);
        return ans;
    }
};