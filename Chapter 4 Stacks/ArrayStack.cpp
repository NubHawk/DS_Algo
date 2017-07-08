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


int main()
{
	struct ArrayStack *S = createStack(10);
	
	for(int i=1; i<10; i++)
		Push(S,10*i);
	for(int i=1; i<10; i++)
		cout << Pop(S) << endl;
}