/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // a是传入的左/右树，b是右/左树，直接比数值就好，左右之分在传参处已经确定
    bool isSame(TreeNode *a, TreeNode *b)
    {
        // 遇到空节点（边界条件）
        if (a == nullptr || b == nullptr)
            return a == b;
        // 没有空节点，a和b是已经传入的两边树的左节点和右节点，即是要比的对象，所以只需要直接开始比数值就行；而后，对称来说，就是本来已经对称的节点互相比一左一右
        return a->val == b->val && isSame(a->left, b->right) && isSame(a->right, b->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root->left, root->right);
    }
};
// @lc code=end
