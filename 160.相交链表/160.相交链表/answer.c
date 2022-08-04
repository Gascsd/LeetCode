#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/intersection-of-two-linked-lists/
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode* curA = headA, * curB = headB;
    int lenA = 1, lenB = 1;
    while (curA->next)//����������β���
    {
        curA = curA->next;
        ++lenA;
    }
    while (curB->next)
    {
        curB = curB->next;
        ++lenB;
    }

    if (curA != curB)//�ж��Ƿ��ཻ
        return NULL;

    struct ListNode* longList = headA, * shortList = headB;
    if (lenA < lenB)
    {
        longList = headB;
        shortList = headA;
    }
    //�����������߲�ಽ
    int gap = abs(lenA - lenB);
    while (gap--)
    {
        longList = longList->next;
    }

    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }

    return longList;
}