/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> map;
        int result = 0;
        while (true)
        {
            result = 0;
            while (n)
            { // 本轮中n=0代表每一位都处理了
                result += (n % 10) * (n % 10);
                n = n / 10;
            }
            // 结束条件
            // 条件1：结果为1
            if (result == 1)
                return true;
            // 条件2：无限循环（遇到了前面有过的数字）
            if (map[result] == 0)
                map[result]++;
            else
                return false;

            n = result; // 下一轮要处理的数字
        }
    }
};
// @lc code=end
