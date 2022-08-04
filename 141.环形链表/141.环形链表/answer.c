#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/linked-list-cycle/
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}