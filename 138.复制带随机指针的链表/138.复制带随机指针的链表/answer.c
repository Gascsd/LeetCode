#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/copy-list-with-random-pointer/

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    struct Node* copy = NULL;
    struct Node* next = NULL;
    //复制节点，链接在原节点的后面
    while (cur)
    {
        //复制链接
        next = cur->next;
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        cur->next = copy;
        copy->next = next;
        //迭代
        cur = next;
    }
    //更新random
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
    //解下来copy节点，回复原链表
    cur = head;
    struct Node* copyHead;
    struct Node* copyTail;
    copyHead = copyTail = NULL;
    while (cur)
    {
        copy = cur->next;
        next = copy->next;
        //取节点尾插
        if (copyTail == NULL)
            copyHead = copyTail = copy;
        else
        {
            copyTail->next = copy;
            copyTail = copyTail->next;
        }
        //恢复原链接
        cur->next = next;
        //迭代器
        cur = next;
    }
    return copyHead;

}