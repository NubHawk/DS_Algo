#include <iostream>
#include <cstdlib>

using namespace std;

struct ArrayStack
{
	int capacity;
	int top;
	char *array;
};

struct ArrayStack *createStack(int capacity)
{
	struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(S == NULL)
		return NULL;
	S->capacity = capacity;
	S->top = -1;
	S->array = (char *)malloc(capacity*sizeof(char));
	
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

void Push(struct ArrayStack *S,char data)
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

bool IsStringPalindrome(string s)
{
	int i=0;
	struct ArrayStack *S = createStack(100);
	
	while(s[i] != 'X')
	{
		Push(S,s[i]);
		cout << "top of stack is " << (char)Top(S) << endl;
		i++;
		
	}
	i++;
	while(s[i] == Top(S) && !IsStackEmpty(S))
	{
			i++;
			cout << "top of stack is " << (char)Top(S) << endl;
			Pop(S);
	}
	if(i != s.length())
		return false;
	else
		return true;
}


int main()
{
	string s;
	cin >> s;
	cout << "palindrome " << IsStringPalindrome(s) << endl;
	
	
}