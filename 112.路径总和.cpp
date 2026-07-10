/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 特殊情况判断
        if (root == nullptr)
            return false;
        // 过程
        targetSum -= root->val;
        // 边界条件,找到叶结点
        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == 0) // 符合条件的路径上的叶结点，此处刚好是0
                return true;
            else
                return false;
        }
        else
            return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum); // 只要有一条路的结果是对的，最后就会返回true，在或的情况下，只有都是false，最终结果才是false
    }
};
// @lc code=end
