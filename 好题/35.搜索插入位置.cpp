/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 开始
        int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
        if (target <= nums[left])
            return 0;
        else if (target > nums[right])
            return right + 1;
        else if (target == nums[right])
            return right;

        // 过程
        while (right - left > 1)
        { // 左右指针相邻或重叠
            // 关键位置检测,因为新的左右就是没被匹配到的mid，最开始的左右也已经经过了检测，所以在循环里就不需要再检测左右了
            // if(target == nums[left]) return left;
            // if(target == nums[right]) return right;
            if (target == nums[mid])
                return mid;
            // 二分查找
            if (target > nums[mid])
                left = mid;
            else if (target < nums[mid])
                right = mid;
            mid = (left + right) / 2;
        }

        // 结束
        if (target > nums[left])
            return left + 1;
        else
            return left; // 用于使返回完备
    }
};
// @lc code=end
