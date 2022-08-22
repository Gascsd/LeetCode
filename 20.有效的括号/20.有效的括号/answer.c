#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/valid-parentheses/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;
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

bool isValid(char* s) {
	Stack st;
	StackInit(&st);

	while (*s)
	{
		if (*s == '{' || *s == '[' || *s == '(')
		{
			StackPush(&st, *s);
		}
		else
		{
			if (StackEmpty(&st))
				return false;
			char top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				return false;
			}

		}
		++s;
	}

	bool flag = StackEmpty(&st);
	StackDestory(&st);
	return flag;
}

int main()
{
	char s[] = "()[]{}";
	if (isValid(s))
	{
		printf("ture");
	}
	else
		printf("false");
	return 0;
}