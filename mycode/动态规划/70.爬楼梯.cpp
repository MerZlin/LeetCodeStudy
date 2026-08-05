/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        // 递推问题
        vector<int> sum(n + 1);
        sum[0] = 1, sum[1] = 1;
        // 第i个问题 = 第i-1个问题 + 第i-2个问题
        for (int i = 2; i <= n; i++)
            sum[i] = sum[i - 1] + sum[i - 2];
        return sum[n];
    }
};
// @lc code=end
