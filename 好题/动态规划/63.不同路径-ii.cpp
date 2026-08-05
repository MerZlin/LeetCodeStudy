/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // 获取所有信息的递推方法
        // int m = obstacleGrid.size(), n = obstacleGrid[0].size(); // 行、列
        // vector f(m + 1, vector<int>(n + 1)); //vector创建二位数组
        // f[0][1] = 1; // 使得进入循环后（1，1）对应1
        // for (int i = 0; i < m; i++)
        //     for (int j = 0; j < n; j++)
        //         if (obstacleGrid[i][j] == 0)
        //             f[i + 1][j + 1] = f[i][j + 1] + f[i + 1][j];
        // // else 默认为0
        // return f[m][n];

        // 空间优化，这题只求答案，前面按行进行遍历，每行只用了一遍，所以可以将所有内容不断取出和更新第一行
        int n = obstacleGrid[0].size();
        vector<int> f(n + 1); // vector创建一维数组
        f[1] = 1;             //(0,0)
        for (auto &row : obstacleGrid)
            for (int i = 0; i < n; i++)
            {
                if (row[i] == 0) // 无障碍，正常更新
                    f[i + 1] += f[i];
                else
                    f[i + 1] = 0;
            }
        return f[n];
    }
};
// @lc code=end
