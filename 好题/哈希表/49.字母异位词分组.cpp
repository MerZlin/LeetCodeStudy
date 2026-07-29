/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // unordered_map<map<char, int>, int> bigmap; //该用法违法
        // map<char,int>可以转为排序后的单词来代替key，int就改为vector<string>直接插入对应结果
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map; // 哈希表分组，对逻辑上相同的map<char，int>进行转换，转变为sort后的string来等价

        for (string &s : strs) // 这里用引用可以节省空间，因为对s只有取值
        {
            string sflag = s;
            ranges::sort(sflag);
            map[sflag].push_back(s);
        }
        // 遍历哈希的方式1
        // for (auto it = map.begin(); it != map.end(); it++)
        //     ans.push_back(it->second);

        // 遍历哈希方式2
        for (auto &[_, value] : map)
            ans.push_back(value);
        return ans;
    }
};
// @lc code=end
