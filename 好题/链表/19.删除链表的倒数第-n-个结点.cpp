/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 2026/7/25
        // 先选一个cul出发，出发n次后再出发一个flag（初始指向dummy）
        ListNode *dummy = new ListNode();
        ListNode *cul;
        ListNode *flag;
        dummy->next = head;
        cul = head;
        flag = dummy;
        int i = 0; // 计次数
        while (true)
        {
            i++;
            if (cul->next == nullptr)
            {
                flag->next = flag->next->next;
                break;
            }
            if (i >= n)
                flag = flag->next;
            cul = cul->next;
        }
        return dummy->next;
    }
};
// @lc code=end
