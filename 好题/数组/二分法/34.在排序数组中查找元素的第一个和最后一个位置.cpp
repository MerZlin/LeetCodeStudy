/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        if (nums.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        // 核心思想二分法推断很快，主要在于边界情况的处理。
        // 其一，默认right和left就是非target，但起初未考虑如果他们初始就是target且从未动过的情况
        // 其二，对于两元素数组比较头痛，所以需要单独对他们进行处理
        int left = 0, right = nums.size() - 1;
        // lmid和rmid是左右两区间内的中点坐标，midl是midr用于找到等于target的边界（这俩始终等于target）
        int mid = (left + right) / 2, lmid = 0, rmid = 0, midl = 0, midr = 0;
        while (right - left > 1) // 对于不在数组的元素，下列循环会陷入死循环
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid; // 注意left和right始终指向非target元素（除非是只有一个元素）
            else if (nums[mid] > target)
                right = mid;
            else // 找到了target
                break;
        }
        // 结束循环只有两种可能，一个是left、right相邻(两元素数组）或相等（单元素数组），一个是mid找到了target
        // left==right对应只有一个元素且为target 或 只有一个元素且不在数组里）
        if (left == right)
        {
            if (nums[left] == target)
            {
                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }
            else
            {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
        }
        else if (left + 1 == right) // 处理不在数组内和两元素数组
        {
            if (nums[left] != target) //(1,4),4
                left++;
            if (nums[right] != target) //(1,4),1
                right--;
            if (left > right) // 两个都不是结果
            {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            // 一个是结果，或这两个都是结果
            ans.push_back(left);
            ans.push_back(right);
            return ans;
        }

        // mid找到了target，针对长度大于等于2的情况(长度为2但只有一个)
        midr = mid;
        midl = mid;
        while (right - midr > 1)
        {
            rmid = (right + midr) / 2;
            if (nums[rmid] > target)
                right = rmid; // right始终指向不为target的元素
            else
                midr = rmid;
        }
        while (midl - left > 1)
        {
            lmid = (left + midl) / 2;
            if (nums[lmid] < target)
                left = lmid;
            else
                midl = lmid;
        }
        // 前面默认right的结果是非target的边界，这里对初始边界进行判断（也就是如果right、left从始至终没动过，而且他就是target的情况进行单独讨论。
        if (nums[right] == target) // 大多数情况返回[l+1，r-1]，所以这里要让结果的r不变，对冲+1
            right++;
        if (nums[left] == target) // left同理
            left--;
        ans.push_back(left + 1);
        ans.push_back(right - 1);
        return ans;
    }
};
// @lc code=end
