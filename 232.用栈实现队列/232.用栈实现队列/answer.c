#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/implement-queue-using-stacks/

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void StackInit(Stack* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//À©ÈÝ
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	//Ñ¹Õ»
	ps->arr[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
int StackSize(Stack* ps)
{
	return ps->top;
}

typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (obj == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	StackInit(&obj->pushST);
	StackInit(&obj->popST);

	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

void PushToPop(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
}

int myQueuePop(MyQueue* obj) {
	PushToPop(obj);

	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);

	return front;
}

int myQueuePeek(MyQueue* obj) {
	PushToPop(obj);
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST)
		&& StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->popST);
	StackDestory(&obj->pushST);

	free(obj);
	obj == NULL;
}
