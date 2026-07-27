/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 用哈希表记录字母个数，第一遍加，第二遍减，因为遇到的相抵最低为0，没遇到的对不上或者有多的相减会小于0
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
            map[s[i]]++;
        for (int i = 0; i < t.size(); i++)
        {
            map[t[i]]--;
            if (map[t[i]] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
