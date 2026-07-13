/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

// 类两数相加题[2]思路
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 开始
        ListNode dummy; // 哨兵
        ListNode *cur = &dummy;
        int num1 = 0, num2 = 0;
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        // 过程
        while (list1 || list2) // 当两个链表都为空时结束循环
        {
            // 记录当前两个节点的值；对空指针获取值可能违法，所以记录
            num1 = -111, num2 = -111;
            if (list1)
                num1 = list1->val;
            if (list2)
                num2 = list2->val;
            // 二者为空的情况会被while拦截，所以下面只会出现剩下三种情况
            if (num1 != -111 && num2 != -111)
            { // 二者都还有节点时
                if (num1 < num2)
                { // 选list1
                    cur = cur->next = new ListNode(num1);
                    list1 = list1->next;
                }
                else
                { // 选list2
                    cur = cur->next = new ListNode(num2);
                    list2 = list2->next;
                }
            }
            else if (num1 == -111)
            { // list1为空
                cur = cur->next = new ListNode(num2);
                list2 = list2->next;
            }
            else if (num2 == -111)
            { // list2为空
                cur = cur->next = new ListNode(num1);
                list1 = list1->next;
            }
        }
        // 结束
        return dummy.next;
    }
};
// @lc code=end
