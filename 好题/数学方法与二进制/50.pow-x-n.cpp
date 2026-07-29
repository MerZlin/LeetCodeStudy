/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        // 缩减指数乘法次数，活用不同指数之积，将总和对应的二进制的各位1，对应要乘的指数，再结合x不断乘自己获得越来越大的x^i，分析发现遇到1就乘入对应的x^i即为最后结果。
        long nflag = n;
        double ans = 1;
        // 预处理负指数情况
        if (nflag < 0)
        {
            x = 1 / x;
            nflag = -nflag;
        }
        while (nflag)
        {
            if (nflag & 1)
                ans *= x;
            x *= x;
            nflag >>= 1; // 右移操作时>>=
            // nflag = nflag >> 1;
        }
        return ans;
    }
};
// @lc code=end
