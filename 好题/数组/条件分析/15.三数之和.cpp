/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int i, j, k, n = nums.size(), last = 0;
        sort(nums.begin(), nums.end()); // 递增
        for (i = 0; i < n - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue; // 防止重复
            // 优化点1：排完序后，当前面和已经大于0，后面的和也一定大于0，可以直接结束，减少循环次数
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            // 优化点2：排完序后，如果当前的nums[i]和最后两个最大的nums的和仍然小于0，说明中间的也一定小于0，可以进入下一个循环，减少循环次数，看新的nums[i]会不会使得和等于0
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue;

            // 转换为参数为-nums[i]的两数之和问题
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                // 利用有序来夹逼
                if (nums[j] + nums[k] > -nums[i])
                    k--; // 多了,需要减少
                else if (nums[j] + nums[k] < -nums[i])
                    j++;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 对于j和k也要判断是否有重复的
                    j++;
                    while (j < n - 1 && nums[j] == nums[j - 1])
                        j++;
                    k--;
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
