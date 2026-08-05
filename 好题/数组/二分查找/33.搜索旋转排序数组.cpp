/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    // 二分法条件分析
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int n = nums.size();
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        // 在交界地带
        if (target > nums[right] && target < nums[left])
            return -1;
        while (right - left > 1) // 解决
        {
            int mid = (left + right) / 2;
            if (nums[left] == target)
                return left;
            if (nums[right] == target)
                return right;
            if (nums[mid] == target)
                return mid;
            // if (nums[n - 1] < nums[0]) // 异常顺序
            // {
            // 找target所在区域来进行操作，左区大，右区小
            // nums[mid]<nums[n-1] === mid在右区
            // nums[mid]>nums[0] === mid在左区
            // 如果target在右区
            if (target < nums[n - 1])
            {
                /*
                if (nums[mid] > nums[0]) // mid在左区
                    left = mid;
                else // mid在右区，也就是正常顺序
                {
                    if (target < nums[mid])
                        right = mid;
                    else
                        left = mid;
                }*/
                // 优化：先走正常顺序，就可以在正常顺序时也能跑，不用单独再写一个判断逻辑
                if (nums[mid] < nums[n - 1]) // mid在右区，正常顺序
                {
                    if (target < nums[mid])
                        right = mid;
                    else
                        left = mid;
                }
                else // mid在左区
                    left = mid;
            }
            // 如果target在左区
            else if (target > nums[0])
            {
                if (nums[mid] > nums[0]) // mid在左区，正常顺序
                {
                    if (target < nums[mid])
                        right = mid;
                    else
                        left = mid;
                }
                else // mid在右区
                    right = mid;
            }
            else
            {
                return -1;
            }
            // }
            // else // 正常顺序
            // {
            //     if (target < nums[mid])
            //         right = mid;
            //     else
            //         left = mid;
            // }
        }
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        return -1;
    }
};
// @lc code=end
