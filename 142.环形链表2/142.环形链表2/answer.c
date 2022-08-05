#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/linked-list-cycle-ii/

//解法1：转换成相交问题
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if (headA == NULL || headB == NULL)
//        return NULL;
//    struct ListNode* curA = headA, * curB = headB;
//    int lenA = 1, lenB = 1;
//    while (curA->next)//遍历链表，找尾结点
//    {
//        curA = curA->next;
//        ++lenA;
//    }
//    while (curB->next)
//    {
//        curB = curB->next;
//        ++lenB;
//    }
//
//    if (curA != curB)//判断是否相交
//        return NULL;
//
//    struct ListNode* longList = headA, * shortList = headB;
//    if (lenA < lenB)
//    {
//        longList = headB;
//        shortList = headA;
//    }
//    //长的链表先走差距步
//    int gap = abs(lenA - lenB);
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    return longList;
//}
//
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow, * fast;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            struct ListNode* meet = fast;
//            struct ListNode* next = meet->next;
//            meet->next = NULL;
//            struct ListNode* ret = getIntersectionNode(head, next);
//            meet->next = next;
//            return ret;
//        }
//    }
//
//    return NULL;
//}



//解法2：公式推导
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode* meet = fast;
            struct ListNode* cur = head;
            while (cur != meet)
            {
                cur = cur->next;
                meet = meet->next;
            }
            return meet;
        }
    }

    return NULL;
}