/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 递归；至少遇到一个空节点时
        if(p == nullptr || q == nullptr) return p == q; //边界条件，遇到空节点，也就是说只有当左树的叶结点和右树同时遇到同一个位置的空节点，那么结构就相同（因为比较的时候都是递归同一个位置），这时候也只会return true；其他情况下就会出现有一个不是空节点，就不同，return false了。
        // 没遇到空节点，正常情况过程：比较根节点，比较左树，比较右树
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
