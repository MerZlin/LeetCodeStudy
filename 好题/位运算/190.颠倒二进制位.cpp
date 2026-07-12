/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution
{
public:
    static constexpr uint32_t flag0 = 0x55555555; // 对换
    static constexpr uint32_t flag1 = 0x33333333; // 两两交换
    static constexpr uint32_t flag2 = 0x0f0f0f0f; // 四四交换
    static constexpr uint32_t flag3 = 0x00ff00ff; // 八八交换

    uint32_t reverseBits32(uint32_t num)
    {
        num = (num & flag0) << 1 | (num >> 1) & flag0;
        num = (num & flag1) << 2 | (num >> 2) & flag1;
        num = (num & flag2) << 4 | (num >> 4) & flag2;
        num = (num & flag3) << 8 | (num >> 8) & flag3;
        return num >> 16 | num << 16;
    }

    int reverseBits(int n)
    {
        return reverseBits32(n);
    }
};
// @lc code=end
