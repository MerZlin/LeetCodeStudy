/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 对数组进行排序，有助于我们减少判断！！！！
        // range::sort(intervals, {}, [](auto& a){return a[0];}); //自己添加排序规则
        ranges::sort(intervals); // 默认按照左端点进行排序
        vector<vector<int>> ans;

        for (auto &p : intervals)
        {
            if (!ans.empty() && p[0] <= ans.back()[1]) // 可合并情况，因为有序，只用判断左端点在不在
                ans.back()[1] = max(p[1], ans.back()[1]);
            else // 开头，以及不可合并情况
                ans.push_back(p);
        }
        return ans;
    }
};
// @lc code=end
