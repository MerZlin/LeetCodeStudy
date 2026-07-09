/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 拆分问题过程为某节点最大深度=max(左子树最大，右子树最大)+1
    int maxDepth(TreeNode *root)
    {
        // 边界情况：遍历到空节点，返回0；
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    // 经验：从递归来看，是从“边界”条件开始“归”，最后才到根得到结果。那么去思考遍历主体（过程）的时候，可以尝试从“第一级到第二级”和“边界条件”这两种情况下手，在这两个情况思考关系。
    // 当然，对于一些别的递归，逐级之间的关系也是需要思考的。
};
// @lc code=end
