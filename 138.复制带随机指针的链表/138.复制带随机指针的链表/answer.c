#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/copy-list-with-random-pointer/

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    struct Node* copy = NULL;
    struct Node* next = NULL;
    //���ƽڵ㣬������ԭ�ڵ�ĺ���
    while (cur)
    {
        //��������
        next = cur->next;
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        cur->next = copy;
        copy->next = next;
        //����
        cur = next;
    }
    //����random
    cur = head;
    while (cur)
    {
        copy = cur->next;

        if (cur->random == NULL)
            copy->random = NULL;
        else
            copy->random = cur->random->next;

        cur = cur->next->next;
    }
    //������copy�ڵ㣬�ظ�ԭ����
    cur = head;
    struct Node* copyHead;
    struct Node* copyTail;
    copyHead = copyTail = NULL;
    while (cur)
    {
        copy = cur->next;
        next = copy->next;
        //ȡ�ڵ�β��
        if (copyTail == NULL)
            copyHead = copyTail = copy;
        else
        {
            copyTail->next = copy;
            copyTail = copyTail->next;
        }
        //�ָ�ԭ����
        cur->next = next;
        //������
        cur = next;
    }
    return copyHead;

}