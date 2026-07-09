// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 第一个为值，第二个为序号
        unordered_map<int, int> answer;
        // 利用哈希查找，结果减其中一个值来找另一个
        for (int i = 0; i < nums.size(); i++)
        {
            auto item = answer.find(target - nums[i]);
            // 找到了说明前面留下的记录和这个就是结果
            if (item != answer.end())
                return {i, item->second};
            // 没找到（==answer.end（））则在哈希表的相应位置留下本数值的记录
            answer[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
