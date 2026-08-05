/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 注意到：矩阵旋转90度 == 1次对角交换+对称进行上下交换
        int n = matrix.size();
        if (n == 1)
            return;
        int flag = 0;
        vector<int> flagl;
        // 对角
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                flag = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = flag;
            }
        }
        // 上下交换
        for (int i = 0; i <= n / 2 - 1; i++)
        {
            flagl = matrix[i];
            matrix[i] = matrix[n - 1 - i];
            matrix[n - 1 - i] = flagl;
        }
        return;
    }
};
// @lc code=end
