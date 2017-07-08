#include <iostream>
#include <cstdlib>

using namespace std;

struct LLNode
{
	int data;
	struct LLNode* next;
};

//insertion

void insert(struct LLNode **head, int data, int pos)
{
	struct LLNode *newNode = (struct LLNode *)malloc(sizeof(struct LLNode));
	if(newNode == NULL)
	{
		cout << "memory error" << endl;
		return;
	}
	newNode->data = data;
	
	struct LLNode *p, *q;
	
	if(pos == 1)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}
	//a
	int k=1;
	p = *head;
	
	while(p != NULL && k < pos)
	{
		q = p;
		p = p->next;
		
		k++;
		
	}
	//at the end of loop, either p->next = NULL or k = pos
	if(k != pos)
	{
		cout << "position does not exist" << endl;
		return;
	}
	
	newNode->next = q->next;
	q->next = newNode;
}

//deletion

void deleteNode(struct LLNode **head, int pos)
{
	struct LLNode *q, *p;
	
	
	if(pos == 1)
	{
		p = *head;
		*head = (*head)->next;
		free(p);
		return;
	}
	
	
	p = *head;
	int k=1;
	while(p != NULL && k < pos)
	{
		q= p;
		p = p->next;
		k++;
	}
	
	if(p == NULL)
	{
		cout <<  "pos does not exist" << endl;
		return;
	}
	
	q->next = p->next;
	free(p);
	
	
	
}

void deleteLL(struct LLNode **head)
{
	struct LLNode *temp = *head;
	
	while(temp)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}

void printList(struct LLNode *head)
{
	if(head == NULL)
		cout << "linked list empty" << endl;
	
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "print succesfull" << endl;
	cout << endl;
}

int main()
{
	struct LLNode *head, *temp;
	head= NULL;
	temp = NULL;
	for(int i=1; i<10; i++)
	{
		insert(&head,10*i,i);
		printList(head);
		/*
		if(i=0)
		{
			head = (struct LLNode *)malloc(sizeof(struct LLNode));
			head->next = NULL;
			temp = head;
		}
		else
			temp->next = (struct LLNode *)malloc(sizeof(struct LLNode));
			temp->next->next = NULL;
		temp->data = 10*i;
		*/
	}
	printList(head);
	for(int i=1; i<10; i+= 2)
	{
		cout << " inserting " << 20*i << "at position "<< i << endl;
		insert(&head, 20*i, i);
		printList(head);
	}
	insert(&head,22,15);
	printList(head);
	insert(&head,23,17);
	for(int i=1; i<10; i+= 2)
	{
		cout << " deleting node at position "<< i << endl;
		deleteNode(&head,i);
		printList(head);
	}
	cout << " deleting node at position 11" << endl;
		deleteNode(&head,11);
		printList(head);
	cout << " deleting node at position 10" << endl;
		deleteNode(&head,10);
		printList(head);	
	
	deleteLL(&head);
	printList(head);
		
}