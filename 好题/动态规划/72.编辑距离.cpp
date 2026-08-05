/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 动态规划问题转化
        // i对应word1，j对应word2
        int m = word1.size(), n = word2.size();
        vector<int> f(n + 1);
        int pre = 0;
        // 初始边界初始化；f[0][j]=dfs(-1,j-1)=j-1 + 1=j,要花费j次删除0~j-1的内容
        for (int j = 0; j < n; j++)
            f[j + 1] = j + 1;
        for (int i = 0; i < m; i++)
        {
            pre = f[0];
            // f[0] = i + 1;
            f[0]++;
            for (int j = 0; j < n; j++)
            {
                int tmp = f[j + 1]; // tmp暂存要被修改的下一轮的左上角
                if (word1[i] == word2[j])
                    f[j + 1] = pre;
                else
                    f[j + 1] = min({f[j], f[j + 1], pre}) + 1;

                pre = tmp;
            }
        }
        return f[n];
    }
};
// @lc code=end
