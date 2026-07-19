/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string flag;
        unordered_map<char, string> map;
        unordered_map<string, char> anti_map; // 双重验证
        int j = 0, sums = 0;                  // s的指针/下标
        for (int i = 0; i < pattern.size(); i++)
        {
            flag = "";
            // 获取string，遇到头或者遇到空格（遇到空格在后，避免到头了下一轮的判断取值超出合法区域
            while (j < s.size() && s[j] != ' ')
                flag += s[j++];
            if (s[j] == ' ')
                sums++; // 记录s的单词个数
            j++;        // 因为遇到空格跳过了，此时需要++

            // 判空处理初始情况(双空说明两个都没遇到);经验：char变量的默认值为0，比较初始情况的时候对char变量判断是否为0
            if (map[pattern[i]] == "" && anti_map[flag] == 0)
            {
                map[pattern[i]] = flag;
                // phase2：双重验证，解决abba与aaaa的bug，只看一边会导致对该情况的误判
                anti_map[flag] = pattern[i];
            }
            // 处理已遇到的情况，进行比较
            else if (flag != map[pattern[i]] || anti_map[flag] != pattern[i])
                return false;
        }
        // pattern多了，s少了
        sums++;
        if (sums < pattern.size())
            return false;
        // pattern少了，s多了
        if (j < s.size())
            return false;

        return true;
    }
};
// @lc code=end
