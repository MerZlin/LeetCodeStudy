/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        if (nums.size() == 1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int start = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 连续性断了
            if ((long)nums[i + 1] - (long)nums[i] > 1)
            {
                if (nums[i] == start)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                start = nums[i + 1];
            }
        }
        // 该情况前面已经push过了，所以这里只需要传入最后一位即可
        if ((long)nums[nums.size() - 1] - (long)nums[nums.size() - 2] > 1)
            ans.push_back(to_string(nums[nums.size() - 1]));
        else
            ans.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));

        return ans;
    }
};
// @lc code=end
