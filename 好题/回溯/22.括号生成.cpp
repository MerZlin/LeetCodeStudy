/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    // 检测串合法
    // bool islegal(string s)
    // {
    //     stack<char> sta;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] == '(')
    //             sta.push(s[i]);
    //         else // 对于‘)’，检测其是否有‘(’
    //         {
    //             if (sta.top() != '(')
    //                 return false;
    //             else
    //                 sta.pop();
    //         }
    //     }
    //     if (sta.empty())
    //         return true;
    //     return false;
    // };
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string path(2 * n, 0);

        // 不论是回溯法还是实时监测，最后的结果都需走完所有可行路径，所以需要在回溯法里判断每位选还是不选（什么条件下可以选什么），最后边界直接返回结果。也就是，因为回溯的分支会消耗栈空间，需要确保每次进入回溯都是有价值的，或是可以及时止损的。
        auto dfs = [&](this auto &&dfs, int left, int right) -> void
        {
            if (left + right == 2 * n)
            {
                ans.push_back(path);
                return;
            }
            // 插入左括号的唯一限制
            if (left < n)
            {
                path[left + right] = '(';
                dfs(left + 1, right);
            }
            // 插入右括号的条件（包含了right<n的隐形条件）
            if (left > right)
            {
                path[left + right] = ')';
                dfs(left, right + 1);
            }
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end
