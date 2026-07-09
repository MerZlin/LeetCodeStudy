/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
/*自改函数，运用递归法
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
    {
        if (l1 == nullptr && l2 == nullptr && carry == 0)
        { // 递归边界
            return nullptr;
        }

        int s = carry;
        if (l1)
        {
            s += l1->val; // 累加进位与节点值
            l1 = l1->next;
        }
        if (l2)
        {
            s += l2->val;
            l2 = l2->next;
        }

        // s 除以 10 的余数为当前节点值，商为进位
        return new ListNode(s % 10, addTwoNumbers(l1, l2, s / 10));
    };
*/

/* 纯迭代
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;         // 哨兵节点
        ListNode *cur = &dummy; // 这里的cur是第一个节点，后面迭代中cur=cur->next尾插不会影响第一个节点的地址，所以dummy.next就是结果的头节点
        int carry = 0;          // 进位值
        while (l1 || l2 || carry)
        { // 有一个不是空节点，或者还有进位，就继续迭代
            int sum = carry;
            if (l1)
            {
                sum += l1->val; // 节点值和进位加在一起
                l1 = l1->next;  // 下一个节点
            }
            if (l2)
            {
                sum += l2->val; // 节点值和进位加在一起
                l2 = l2->next;  // 下一个节点
            }
            cur = cur->next = new ListNode(sum % 10); // 新建尾插节点，每个节点保存一个数位
            carry = sum / 10;                         // 新的进位
        }
        return dummy.next; // 哨兵节点的下一个节点就是头节点
    }
};
*/

/*自己手敲版*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 该题目的处理流程是类似的，所以可以用一个迭代框架套上去。phase1
        // 开始phase1；我们需要获得每一位的和的值，直接加到节点和用变量赋值虽然一样，但用变量不会多太多开销，也可以获得更多操作自由度，
        int s = 0;     // 每一位的和
        int carry = 0; // 进位
        // 开始phase2，
        ListNode dummy;         // 哨兵节点指向头节点；phase3：因为next是指针，且后面cur需要取到地址，所以dummy节点本身不应该是指针，而是对象。
        ListNode *cur = &dummy; // 因为初始只拥有哨兵，且过程中可以满足cur = cur->next的移动，所以初始将cur赋值为dummy的地址，那么dummy.next也就是第一次的cur->next，也就是第一个赋值节点（头节点），所以最后返回dummy.next

        // 过程处理
        while (l1 || l2 || carry) // phase1：判断结束情况：结束时，两个都到头（遍历到空指针，l1，l2为否），且没有进位了（carry==0，对应判断也为否）。phase2：carry用于判断最后两个都加完了，有无进位的情况
        {
            // 单位求和。phase1
            s = carry; // carry只会为1或0，用于存进位结果
            if (l1)
            { // 为空节点时就不会再参与计算了
                s += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                s += l2->val;
                l2 = l2->next;
            }
            // 以上获得了和。phase1
            // 需要插入新节点来凑结果格式，利用数据结构的ListNode(int x, ListNode *next) : val(x), next(next) {}来创建节点。phase1
            // 但是如果我们直接创建节点，然后不断往后推进，最后就找不到头节点了，因此我们需要一个能指向头节点的前空间节点，也可以称之为哨兵节点dummy，来指向用于返回的最终结果。然后有了头节点，我们需要怎么推进节点来不断创建新节点赋值？就需要一个表示当前节点的变量cur来进行每位节点的处理了。哨兵节点并不参与过程，所以只需要写在开始部分，cur参与过程。phase2。
            // 因为cur->next默认是空指针，所以需要先创建一个对象赋予它（为空指针申请空间），才能让cur能往后移动；且这样每个节点的地址都是固定的
            cur->next = new ListNode(s % 10);
            cur = cur->next;
            carry = s / 10; // 获取进位
        }
        // 结束
        return dummy.next; // 见开始部分的分析
    }
};
// @lc code=end
