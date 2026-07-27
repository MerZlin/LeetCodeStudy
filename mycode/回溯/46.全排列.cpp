/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> path;
        vector<vector<int>> ans;
        unordered_map<int, int> map;
        int n = nums.size();

        // 回溯法
        auto dfs = [&](this auto &&dfs, int i) -> void
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            for (int j = 0; j < n; j++)
            {
                if (map[nums[j]] == 0)
                {
                    path.push_back(nums[j]);
                    map[nums[j]]++;
                    dfs(i + 1);
                    map[nums[j]]--;
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end
