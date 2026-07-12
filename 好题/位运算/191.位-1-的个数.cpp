/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    static int hammingWeight(int n)
    {
        /*逐位检测
        int cnt = 0;
        for (int i = 0; i < 32;i++){
            // if(n & (1<<i)) cnt++;
            cnt += n & (1 << i);
        }*/
        // 计算优化，n & (n-1)的结果会把当前的下一位1给变掉，也就是一次计算消耗一个1，总共会进行1的个数-1次计算，那么就会有1的个数-1次计数，加上初始进入循环的那一次，就刚好是最后的结果，这种方法可以减少关于0的检测
        int cnt = 0;
        // 最后一次检测到1，计算使得结果没有1了，但是会先计数在进入下次循环
        while (n)
        {
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end
