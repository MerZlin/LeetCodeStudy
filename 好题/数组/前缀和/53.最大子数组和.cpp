/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 前缀和+贪心
        int ans = INT_MIN;
        int presum = 0, minpresum = 0;
        for (int x : nums)
        {
            presum += x;
            ans = max(ans, presum - minpresum);
            minpresum = min(minpresum, presum);
        }
        return ans;
    }
};
// @lc code=end
