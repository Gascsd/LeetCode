#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/remove-linked-list-elements/
 

// 解法一
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



//解法二
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* newhead = NULL, * tail = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            //尾插
            if (tail == NULL)//放入头节点
            {
                newhead = tail = cur;
            }
            else//放入其他节点
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
    //防止最后一个节点存放val元素会有野指针的问题
    if (tail)
        tail->next = NULL;

    return newhead;
}