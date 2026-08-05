/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // cul = nullptr;cul 只是一个指针变量,它存储的是某个节点的内存地址。执行 cul = nullptr;只是让这个指针不再指向原来的节点，但原来那个节点本身（及其 next 指针）完全不受影响。
        // 无法撤销已经修改的节点连接
        // 要断开环，你必须将某个节点的 next 置为 nullptr，而不是将某个指针置为 nullptr。

        // 先成环，利用长度k的新头和剩下的length-k的旧头，这个数值关系进行移动
        if (head == nullptr)
            return head;
        int length = 1;
        ListNode *tail = head;
        while (tail->next != nullptr) // 从头节点开始遍历，如果当前是最后一个节点就停止。
        {
            length++; // 举例子，只有1个或两个的情况
            tail = tail->next;
        }
        k %= length;
        if (k == 0)
            return head;

        // 此时tail已经是尾节点了
        tail->next = head; // 成环，进行头节点移动

        // 根据画图分析，移动length - k - 1次到新尾节点
        ListNode *newtail = head;
        for (int i = 0; i < length - k - 1; i++)
            newtail = newtail->next;

        // 新的头节点就是新尾节点的下一个
        ListNode *newhead = newtail->next;
        newtail->next = nullptr; // 断环只能通过next来操作
        return newhead;
    }
};
// @lc code=end
