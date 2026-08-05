/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        string s = "";
        string ans = "";
        int i;
        stack<string> sta; // 因为返回上一级目录需要记录最新最近的目录，所以用栈来处理
        for (i = 0; i <= path.size(); i++)
        {
            // 遇到/或最后一位开始结算;
            if (i == path.size() || path[i] == '/')
            {
                // 遇到斜杠时，s为空串说明一直遇到斜杠，继续无视。
                if (s == "")
                    continue;
                // 剩下的情况说明写入东西了
                else if (s == ".")
                    s = ""; // 本目录不做操作
                else if (s == "..")
                {
                    if (!sta.empty())
                        sta.pop();
                    s = "";
                }
                else
                {
                    // 旧结算
                    s = "/" + s;
                    sta.push(s);
                    // 新开始
                    s = "";
                }
            }
            else
                s += path[i];
        }
        if (sta.empty()) // 循环下来要么被返回完了，要么没遇到有效地址，只返回根目录
            ans = "/";
        while (!sta.empty())
        {
            ans = sta.top() + ans;
            sta.pop();
        }
        return ans;
    }
};
// @lc code=end
