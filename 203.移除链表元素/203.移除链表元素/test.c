#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/remove-linked-list-elements/
 

// �ⷨһ
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            if (cur == head)
//            {
//                head = head->next;
//                free(cur);
//                cur = head;
//            }
//            else
//            {
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}



//�ⷨ��
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* newhead = NULL, * tail = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            //β��
            if (tail == NULL)//����ͷ�ڵ�
            {
                newhead = tail = cur;
            }
            else//���������ڵ�
            {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
        }
        else
        {
            struct ListNode* del = cur;
            cur = cur->next;
            free(del);
        }
    }
    //��ֹ���һ���ڵ���valԪ�ػ���Ұָ�������
    if (tail)
        tail->next = NULL;

    return newhead;
}