/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        // 等长
        if (a.size() == b.size())
        {
            for (int i = a.size() - 1; i >= 0; i--)
            {
                int num1 = (int)a[i] + (int)b[i] - 2 * (int)'0';
                a[i] = char('0' + num1 % 2); // 先处理本位
                if (num1 > 1)
                { // 有进位
                    if (i == 0)
                        return "1" + a; // 结束情况1
                    else
                        a[i - 1] += 1;
                }
                else
                {
                    if (i == 0)
                        return a; // 结束情况2
                }
            }
        }
        // 不等长默认a长
        if (a.size() < b.size())
        {
            string sflag = b;
            b = a;
            a = sflag;
        }
        // 处理短的部分
        for (int i = 0; i < b.size(); i++)
        {
            int num = (int)a[a.size() - 1 - i] + (int)b[b.size() - 1 - i] - 2 * (int)'0';
            a[a.size() - 1 - i] = char('0' + num % 2); // 本位更新
            if (num > 1)
                a[a.size() - 2 - i] += 1; // 进位
        }
        for (int i = a.size() - b.size() - 1; i >= 0; i--)
        {
            int numflag = (int)a[i] - (int)'0';
            a[i] = char('0' + numflag % 2);
            if (numflag > 1) // 进位
            {
                if (i == 0)
                    return "1" + a; // 结束情况1
                else
                    a[i - 1] += 1;
            }
        }
        return a; // 结束情况2
    }
};
// @lc code=end
