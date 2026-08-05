/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // method 1：矩阵递推
        // int m = grid.size(), n = grid[0].size();
        // vector f(m + 1, vector<int>(n + 1));
        // for (int i = 0; i <= m; i++)
        //     f[i][0] = INT_MAX / 2;
        // for (int j = 0; j <= n; j++)
        //     f[0][j] = INT_MAX / 2;
        // f[0][1] = 0;
        // for (int i = 0; i < m; i++)
        //     for (int j = 0; j < n; j++)
        //         f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + grid[i][j];
        // return f[m][n];
        // method 2：空间优化
        int n = grid[0].size(), i = 0;
        vector<int> f(n + 1);
        for (i = 0; i <= n; i++)
            f[i] = INT_MAX / 2;
        f[1] = 0;
        for (auto &row : grid)
            for (i = 0; i < n; i++)
                f[i + 1] = min(f[i], f[i + 1]) + row[i];
        return f[n];
    }
};
// @lc code=end
