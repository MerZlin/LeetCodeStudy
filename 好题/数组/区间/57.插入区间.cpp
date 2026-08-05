/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // 类合并区间操作，对于要插入的区间也是当作一个还未遍历的区间来看
        ranges::sort(intervals); // 先排序数组减少判断条件
        vector<vector<int>> ans;
        int flag = 1, n = intervals.size(); // 检测是否已经插入，减少判断次数
        if (n == 0)
            ans.push_back(newInterval);
        for (auto &p : intervals)
        {
            if (flag)
            {
                if (!ans.empty() && newInterval[0] <= ans.back()[1]) // 有重叠
                {
                    ans.back()[1] = max(newInterval[1], ans.back()[1]);
                    flag = 0;
                }
                else if (newInterval[0] <= p[0]) // 比下一个要插入的区间更靠前，则先插入进去(包括开头插入；比如new:[0,3],p:[1,4])；如果是new[0]>p[0]，那等到下次循环再判断有无重叠
                {
                    ans.push_back(newInterval);
                    flag = 0;
                }
            }
            if (!ans.empty() && p[0] <= ans.back()[1]) // 有重叠
                ans.back()[1] = max(p[1], ans.back()[1]);
            else
                ans.push_back(p);
        }
        if (flag) // 在所有区间的最后
        {
            if (newInterval[0] <= ans.back()[1]) // 有重叠
            {
                ans.back()[1] = max(newInterval[1], ans.back()[1]);
                flag = 0;
            }
            else
                ans.push_back(newInterval);
        }
        return ans;
    }
};
// @lc code=end
