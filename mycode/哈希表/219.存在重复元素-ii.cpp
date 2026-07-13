/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        // 特殊情况，0用于判断没遇到，其余正数用于记录上一次见到的坐标。
        map[nums[0]] = -1;
        for (int j = 1; j < nums.size(); j++)
        {
            // 没遇到过
            if (map[nums[j]] == 0)
                map[nums[j]] = j;
            // 遇到过
            else
            {
                // 上一个是头节点
                if (map[nums[j]] == -1)
                {
                    if (j <= k) // j-0<=k
                        return true;
                    // else map[nums[j]] = j;
                }
                else
                {
                    if (j - map[nums[j]] <= k)
                        return true;
                    // else map[nums[j]] = j;
                }
                // 上面两个else的内容可以合并简化
                map[nums[j]] = j;
            }
        }
        return false;
        // 时间复杂度O(n)
    }
};
// @lc code=end
