/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        // 层序遍历，广度优先搜索；利用队列辅助实现
        /*层序遍历迭代法
        初始将根节点入队
        while(队列非空)
            记录队列长度
            for(队列长度)   //遍历一层
                取节点并pop出去
                若 节点->左 存在，push到队列中
                若 节点->右 存在，push到队列中
        */
        queue<TreeNode *> que;
        que.push(root);
        vector<double> result;
        // 一次while是处理一层
        while (!que.empty())
        {
            // 队列长度,一层的节点个数
            int size = que.size();
            // 记录层和
            double sum = 0;
            // 遍历一层
            for (int i = 0; i < size; i++)
            {
                // 获取这层的每个节点并pop掉
                TreeNode *flag = que.front();
                que.pop();
                // 记录层和
                sum += flag->val;
                // 传入下一层节点
                if (flag->left)
                    que.push(flag->left);
                if (flag->right)
                    que.push(flag->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};
// @lc code=end
