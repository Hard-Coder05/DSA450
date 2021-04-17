class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int visited[n + 1];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            if (visited[nums[i] + 1] == 1)
                return nums[i];
            else
                visited[nums[i] + 1] = 1;
        }
        return -1;
    }
};