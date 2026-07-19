/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    // 中序遍历；函数内自定义函数
    int getMinimumDifference(TreeNode *root)
    {
        // 二叉搜索树的中序遍历为有序数组；自定义函数
        // 本问题转化为，寻找有序数组相邻之差最小的结果
        // 对于数组的最开始，mincha要尽可能大，第一的pre要是尽可能远的负数，但因为我们这里采用“当前-pre”，所以这里pre不能是最小，给他除2来防止溢出
        int mincha = INT_MAX;
        int pre = INT_MIN / 2;
        // 方法内实现自定义函数写法;前面是函数名，后面是参数，然后用箭头指向函数返回类型和主体
        auto mid = [&](this auto &&mid, TreeNode *node) -> void
        {
            if (node == nullptr)
                return;
            mid(node->left);
            mincha = min(mincha, node->val - pre);
            pre = node->val;
            mid(node->right);
        }; // 注意这里的自定义函数的末尾要加一个分号

        // 中序遍历
        mid(root);
        return mincha;
    }
};
// @lc code=end
