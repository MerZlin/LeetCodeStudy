/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int i = 0, j = 0, k = 0;
        unordered_map<char, int> map;
        // 行
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (map[board[i][j]] == 0)
                    map[board[i][j]]++;
                else
                    return false;
            }
            // 恢复现场
            for (auto it = map.begin(); it != map.end(); ++it)
            {
                map[it->first] = 0;
            }
        }
        // 列
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (map[board[j][i]] == 0)
                    map[board[j][i]]++;
                else
                    return false;
            }
            for (auto it = map.begin(); it != map.end(); ++it)
            {
                map[it->first] = 0;
            }
        }
        // 块
        for (i = 1; i < 9; i += 3)
        {
            for (j = 1; j < 9; j += 3)
            {
                for (k = -1; k < 2; k++)
                {
                    if (map[board[i + k][j - 1]] != 0 || map[board[i + k][j]] != 0 || map[board[i + k][j + 1]] != 0)
                        return false;
                    if (board[i + k][j - 1] != '.' && map[board[i + k][j - 1]] == 0)
                        map[board[i + k][j - 1]]++;
                    if (board[i + k][j] != '.' && map[board[i + k][j]] == 0)
                        map[board[i + k][j]]++;
                    if (board[i + k][j + 1] != '.' && map[board[i + k][j + 1]] == 0)
                        map[board[i + k][j + 1]]++;
                }
                for (auto it = map.begin(); it != map.end(); ++it)
                {
                    map[it->first] = 0;
                }
            }
        }
        return true;
    }
};
// @lc code=end
