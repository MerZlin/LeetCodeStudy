/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // magazine的字符数要够ransomNote取，所以先统计magazine的字符数量，拿ransomNote减，最后判断相关字符<0即为不够。
        if (ransomNote.size() > magazine.size())
            return false;
        unordered_map<char, int> map;
        int i = 0;
        for (i = 0; i < magazine.size(); i++)
            map[magazine[i]]++;
        for (i = 0; i < ransomNote.size(); i++)
        {
            map[ransomNote[i]]--;
            // 说明ran需要的字符多于ma的，不够取，不符合条件
            if (map[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
