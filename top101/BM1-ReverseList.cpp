#include "ListNode.h"


// 迭代
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr || pHead->next == nullptr) {
        return pHead;
    }
    ListNode * prev = nullptr;
    ListNode * curr = pHead;
    while (curr != nullptr) {
        ListNode *temp = curr->next;    // 记录后值
        curr->next = prev;  // 断链，指前
        prev = curr;    // prev 后移
        curr = temp;    // curr 后移
    }
    return prev;
}

//  头插法
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr || pHead->next == nullptr) {
        return pHead;
    }
    ListNode *prev = new ListNode(-1);
    prev->next = pHead;
    ListNode *curr = pHead;
    while (curr != nullptr) {
        ListNode *temp = curr->next;
        curr->next = temp->next;    // curr 指向后一个
        temp->next = prev->next;
        prev->next = temp;
    }
    return prev->next;
}


// 递归
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr || pHead->next == nullptr) {
        return pHead;
    }
    ListNode *newHead = ReverseList(pHead->next);
    pHead->next->next = pHead;
    // 这里置空的话持续向后递归时怎么变？
    //  注意，先往后递归，后面再返回，会先变为 null，再更改为正确值。
    pHead->next = nullptr;
    return newHead;
}