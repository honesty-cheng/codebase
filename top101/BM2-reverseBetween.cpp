#include "ListNode.h"
#include <iostream>
using namespace std;

// 头插法 + 迭代法
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode *res = new ListNode(-1);
    res->next = head;
    ListNode *prev = res;
    ListNode *curr = head;
    for (size_t i = 1; i < m; i++)
    {
        prev = prev->next;
        curr = curr->next;
    }
    //  头插法
    for (size_t i = m; i < n; i++)
    {
        ListNode *temp = curr->next; //  记录 curr 后一个元素（temp)
        curr->next = temp->next;     // curr 断开后一个元素，连到后后（curr向后走）
        temp->next = prev->next;     // 后一个元素(temp)连到 prev后（头插）
        prev->next = temp;           // prev 连到 temp 上（头插）
    }
    return res->next;
}

// 扩展思路：递归？？？
// 反转从 m 开始，n 位。
// 其实没看懂，不想看了
ListNode *temp = nullptr;
ListNode *reverse(ListNode *head, int n)
{
    if (n == 1)
    { // 只颠倒第一个节点，后续不管 temp = head->next;
        temp = head->next;
        return head;
    }
    ListNode *node = reverse(head->next, n - 1); // 进入子问题
    head->next->next = head;                     // 反转
    head->next = temp;                           // 拼接
    return node;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m == 1) // 从第一个节点开始
        return reverse(head, n);
    ListNode *node = reverseBetween(head->next, m - 1, n - 1); // 缩减子问题
    head->next = node;
    return head;
}