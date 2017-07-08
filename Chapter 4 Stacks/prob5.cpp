#include <iostream>
#include <cstdlib>

using namespace std;

struct ArrayStack
{
	int capacity;
	int top;
	int *array;
};

struct ArrayStack *createStack(int capacity)
{
	struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(S == NULL)
		return NULL;
	S->capacity = capacity;
	S->top = -1;
	S->array = (int *)malloc(capacity*sizeof(int));
	
	if(S->array == NULL)
		return NULL;
	
	return S;
}

int IsStackFull(struct ArrayStack *S)
{
	return S->top == S->capacity -1;
}

int IsStackEmpty(struct ArrayStack *S)
{
	return S->top == -1;
}

void Push(struct ArrayStack *S,int data)
{
	if(IsStackFull(S))
	{
		cout << "Stack Overflow" << endl;
		return;
	}
	
	S->array[++S->top] = data;
}

int Pop(struct ArrayStack *S)
{
	if(IsStackEmpty(S))
	{
		cout << "Stack Underflow" << endl;
		return -1;
	}
	return S->array[S->top--];
}

int Top(struct ArrayStack *S)
{
	if(IsStackEmpty(S))
		return -1;
	return S->array[S->top];
}

void DeleteStack(struct ArrayStack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}	
}

struct AdvancedStack
{
	struct ArrayStack *elementStack;
	struct ArrayStack *minStack;
};

struct AdvancedStack *createAdvancedStack(int capacity)
{
	struct AdvancedStack *S = (struct AdvancedStack *)malloc(sizeof(struct AdvancedStack));
	
	if(S == NULL)
		return NULL;
	
	S->elementStack = createStack(capacity);
	S->minStack = createStack(capacity);
	
	return S;
}

void Push(struct AdvancedStack *S, int data)
{
	if(IsStackFull(S->elementStack))
	{
		cout << "Stack Overflow" << endl;
		return;
	}
	
	Push(S->elementStack,data);
	if(data < Top(S->minStack) || IsStackEmpty(S->minStack))
		Push(S->minStack, data);
	else
		Push(S->minStack, Top(S->minStack));
	
}

int Pop(struct AdvancedStack *S)
{
	if(IsStackEmpty(S->elementStack))
	{
		cout << "Stack Underflow" << endl;
		return -1;
	}
	
	Pop(S->minStack);
	return Pop(S->elementStack);
}

int GetMinimum(struct AdvancedStack *S)
{
	if(IsStackEmpty(S->elementStack))
		return -1;
	return Top(S->minStack);
}


int main()
{
	struct AdvancedStack *S = createAdvancedStack(100);
	
	for(int i=1; i<10; i++)
	{
		Push(S,10*i);
		cout << "min element is " << GetMinimum(S) << endl;
	}
	for(int i=10; i>1; i--)
	{
		Push(S,i);
		cout << "min element is " << GetMinimum(S) << endl;
	}
	for(int i=1; i<20; i++)
		cout << Pop(S) << endl;
	
	
	
}