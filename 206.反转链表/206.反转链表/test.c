#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode.cn/problems/reverse-linked-list/


struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;

    while (cur)
    {
        next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }

    return newhead;
}

