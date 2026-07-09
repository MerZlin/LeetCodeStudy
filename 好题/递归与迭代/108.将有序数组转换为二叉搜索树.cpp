/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *dfs(vector<int> &nums, int left, int right)
    {
        // 边界条件,只有一个数值时，父调用就是TreeNode(x,dfs(0,0),dfs(0,0)),父调用创建节点，该父调用过程中调用的dfs的就是边界条件，也就是真正的边界；只会因为left==right返回null。规则是不断创建节点和左右子树，边界是左右子树不存在，返回null。换句话说，规则上来说，当左右子树都没有的时候，就是叶结点，此时可以看成只有一个数的数组，这种时候不好输入两个0来判断，加上二分mid=（left+right）/2，其向下兼容，最后mid会不断向左跑，这样哪怕是最后一位，参与创建节点也只会有num[mid]，这个mid因为二分的向下兼容就刚好是num.size-1，所以我们可以令left=0，right=num.size(),也因此，在左子树递归中，我们的right传入每次的mid,而我们的右子树中mid+1最大也就是right，相当于在计算中整体往右移了一位。
        if (left == right)
            return nullptr;
        // 因为是有序数组，将数组不断对半分，左边是左子树，右边是右子树，就可以得到平衡二叉搜索树
        // 利用该初始化TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        int mid = (left + right) / 2;
        return new TreeNode(nums[mid], dfs(nums, left, mid), dfs(nums, mid + 1, right));
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size());
    }
};
// @lc code=end
