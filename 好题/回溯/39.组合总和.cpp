/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // 子集型回溯
        int n = candidates.size();
        vector<int> path;
        vector<vector<int>> ans;

        auto dfs = [&](this auto &&dfs, int i, int left) -> void
        {
            // 边界条件
            // if (i == n || left - candidates[i] < 0) //这种提前判断结果只适用于有序数组
            if (i == n || left < 0)
                return;

            // 满足结果，推送并返回
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }
            // 选择填入当前元素
            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back(); // 恢复现场
            // 不选
            dfs(i + 1, left);
        };
        dfs(0, target);
        return ans;
    }
};
// @lc code=end
