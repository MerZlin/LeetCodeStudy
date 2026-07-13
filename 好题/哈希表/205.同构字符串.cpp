/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start

// 暂未查看更好的实现，当前是我的实现
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        if (s == t)
            return true;
        // 接下来的就是每一位需要映射到其他位的情况
        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        unordered_map<int, int> mapsum;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 从头开始，则对应的位置应该是同时多一个或者同时为1。
            maps[s[i]]++;
            mapt[t[i]]++;
            // 如果第一个条件不满足（也就是出现的不相等时），一定有问题
            if (maps[s[i]] != mapt[t[i]])
                return false;
            // 上面的方法解决大部分情况，对于特殊情况：保存并判断两个字符串每一位的差距；因为对应得情况已经保存，当遇到同一个字符，对应结果不同则和不同于之前保存的结果，所以是不对的。
            sum = (int)s[i] + (int)t[i];
            if (mapsum[s[i]] == 0)
                mapsum[s[i]] = sum;
            else if (mapsum[s[i]] != sum)
                return false;
        }
        return true;
    }
};
// @lc code=end
