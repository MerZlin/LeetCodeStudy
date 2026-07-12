/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;                                // map[first]就是其second的值
        for (auto it = map.begin(); it != map.end(); it++) // 哈希表的遍历
            if (it->second == 1)
                return it->first; // it->first就是map[]内的下标，也就是对应的nums[i]
        return 0;
    }
};
// @lc code=end
