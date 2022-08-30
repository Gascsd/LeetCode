#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/design-circular-queue/

typedef struct {
    int* a;
    int front;
    int back;
    int N;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->back = 0;
    obj->N = k + 1;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->back;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->back + 1) % obj->N == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    return false;

    obj->a[obj->back] = value;
    obj->back++;

    //对于到空间尾以后的处理
    obj->back %= obj->N;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj));
    return false;

    obj->front++;

    //对于到空间尾以后的处理
    obj->front %= obj->N;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->back - 1 + obj->N) % obj->N];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}
