/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int length = digits.size();
        digits[length - 1]++;
        while (length--)
        {
            // 对每个本位进行判断
            if (digits[length] >= 10)
            {
                digits[length] = digits[length] % 10;
                if (length == 0) // 最高位进位
                {
                    // digits->insert(0, 1);
                    digits.push_back(0);
                    for (int i = digits.size() - 1; i > 0; i--)
                    {
                        digits[i] = digits[i - 1];
                    }
                    digits[0] = 1;
                }
                else
                    digits[length - 1]++;
            }
        }
        return digits;
    }
};
// @lc code=end
