/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 预处理方向数组
        int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size(); // m是行数，n是列数
        int size = m * n;                            // 总遍历次数
        int i = 0, j = -1;                           // 初始启动位置
        for (int dir = 0; ans.size() < size; dir = (dir + 1) % 4)
        {
            for (int k = 0; k < n; k++) // 第一次循环里小于n就是遍历一行，下一次循环就是遍历一列
            {
                i += DIR[dir][0];
                j += DIR[dir][1];
                ans.push_back(matrix[i][j]);
            }
            m--;        // 第一次循环里，一次遍历少一行，下一次循环就是一次遍历少一列
            swap(n, m); // 交换次数，本次是行下一次就是处理列。
        }
        return ans;
    }
};
// @lc code=end
