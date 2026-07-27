/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        // 回溯法，本质深度优先搜索，遍历完一个结果存一个结果。
        // 回溯三问：
        // 当前问题：构造字符串>=i的部分
        // 当前操作：枚举path[i]要填入的内容
        // 下一个子问题：构造字符串>=i+1的部分
        // string数组赋值要用大括号
        string s[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"};

        int len = digits.size();
        vector<string> ans;
        string path(len, 0); // 长度为len，每位为char值为0的字符

        auto dfs = [&](this auto &&dfs, int i) -> void
        {
            // 边界条件
            if (i == len) // len-1时刚塞入最后一位，才调用dfs(len)到此处
            {
                ans.push_back(path);
                return;
            }
            // 非边界条件
            for (char c : s[digits[i] - '0']) // 枚举字符
            {
                path[i] = c; // 回来会覆盖，不用恢复现场
                dfs(i + 1);
            }
        }; // 记得加分号

        dfs(0);
        return ans;
    }
};
// @lc code=end
