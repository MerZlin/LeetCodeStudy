/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode *invertTree(TreeNode *root)
    {
        // 总翻转=每个节点进行左翻转+右翻转

        // 结束：对于空节点直接返回即可
        if (root == nullptr)
            return root;

        // 过程，不断递归到左右子树，不需要返回，只需要让操作主体不断操作即可
        invertTree(root->left);
        invertTree(root->right);
        // 递归过程主体，进行左右交换，然后返回：最先从叶子节点进行，不断向上
        TreeNode *flag = root->left;
        root->left = root->right;
        root->right = flag;

        return root;
    }
};
// @lc code=end
