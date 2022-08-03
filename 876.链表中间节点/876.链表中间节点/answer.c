#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode.cn/problems/middle-of-the-linked-list/

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast, * slow;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}