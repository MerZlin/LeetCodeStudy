/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int flag = x;
        string s;
        // 当本位（最后一位）为0，也就是两个都是非，所以用或
        // 对于x=0的情况单独判断，因为这个while循环遇到0就结束，当数值只有0的时候s就为空了。
        while (flag % 10 != 0 || flag / 10 != 0)
        {
            // s += flag % 10; //本行代码具有问题，应该改为下面的代码
            s += char('0' + flag % 10);
            flag = flag / 10;
        }
        // i要到中位数的位置，所以要取等
        for (int i = 0; i <= (s.size() - 1) / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};
// @lc code=end
