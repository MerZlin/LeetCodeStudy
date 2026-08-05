/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // 开始：为奇数则false；申请栈和队列
        if (s.length() % 2 != 0)
            return false;
        stack<int> st;
        // 过程
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty()) // 右括号但没有左括号
                    return false;
                if (s[i] == ']')
                {
                    if (st.top() != '[')
                        return false;
                    st.pop();
                }
                else if (s[i] == ')')
                {
                    if (st.top() != '(')
                        return false;
                    st.pop();
                }
                else if (s[i] == '}')
                {
                    if (st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        // 结束
        if (!st.empty())
            return false;
        return true;
    }
};
// @lc code=end
