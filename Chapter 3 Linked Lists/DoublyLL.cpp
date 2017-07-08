#include <iostream>
#include <cstdlib>

using namespace std;

struct DLLNode
{
	int data;
	struct DLLNode *left, *right;
};

void insert(struct DLLNode **head, int data, int pos)
{
	struct DLLNode *newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	
	struct DLLNode *p =NULL,*q = NULL;
	if(pos == 1)
	{
		newNode->right = *head;
		newNode->left = NULL;
		if(*head)
			(*head)->left = newNode;
		
		*head = newNode;
		return;
	}
	
	int k = 1;
	p = *head;
	while(p != NULL && k < pos)
	{
		q= p;
		p = p->right;
		k++;
	}
	if(k != pos)
	{
		cout << "pos does not exist" << endl;
		return;
	}
	
	q->right = newNode;
	newNode->right = p;
	newNode->left = q;
	if(p != NULL)
	{
		p->left = newNode;
	}
}

void deleteNode(struct DLLNode **head, int pos)
{
	struct DLLNode *temp;
	temp = *head;
	
	if(pos == 1)
	{
		temp = *head;
		*head = (*head)->right;
		free(temp);
		return;
	}
	
	int k =1;
	while(temp != NULL && k < pos)
	{
		temp = temp->right;
		k++;
	}
	if(temp == NULL)
	{
		cout << "pos does not exist" << endl;
		return;
	}
	
	struct DLLNode *p;
	p = temp->left;
	
	p->right = temp->right;
	temp->right->left = p;
	
	free(temp);
	
	
}

void printLL(struct DLLNode *head)
{
	while(head)
	{
		cout << head->data << " ";
		head= head->right;
	}
	cout << "print succesfull" << endl;
	cout << endl;
}

int main()
{
	struct DLLNode *head=NULL;
	for(int i=0; i<10; i++)
	{
		insert(&head,10*i,1);
		printLL(head);
		
	}
	for(int i=1; i<10; i+= 2)
	{
		cout << " inserting " << 20*i << "at position "<< i << endl;
		insert(&head, 20*i, i);
		printLL(head);
	}
	cout << "inserting at pos 16 " << endl;
	insert(&head,22,16);
	printLL(head);
	insert(&head,23,22);
	
	for(int i=1; i<10; i+= 2)
	{
		cout << " deleting node at position "<< i << endl;
		deleteNode(&head, i);
		printLL(head);
	}
	
}