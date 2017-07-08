#include <iostream>
#include <cstdlib>

using namespace std;


struct LLNode
{
	int data;
	struct LLNode* next;
};

//Recursive
struct LLNode* ReverseLLinPairsRecursive(struct LLNode *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	//1st node is head, second is temp
	struct LLNode* temp = head->next;
	
	//swap them
	head->next = temp->next;
	temp->next = head;
	head = temp;
	
	//recursive call
	head->next->next = ReverseLLinPairsRecursive(head->next->next);
	
	return head;
	
}

void printLL(struct LLNode* head)
{
	struct LLNode* tmpPtr = head;
	while(tmpPtr)
	{
		cout << tmpPtr->data << " ";
		tmpPtr = tmpPtr->next;
		
	}
}


int main()
{
	struct LLNode* newNode;
	newNode = (struct LLNode*)malloc(sizeof(struct LLNode));
	
	newNode->data = 5;
	
	struct LLNode* tmpPtr;
	tmpPtr = newNode;
	for(int i=0; i<5;i++)
	{
		struct LLNode* tmpNode = (struct LLNode*)malloc(sizeof(struct LLNode));
		tmpNode->data = 10*i;
		
		tmpPtr->next = tmpNode;
		tmpNode->next = NULL;
		tmpPtr = tmpPtr->next;
	}
	
	printLL(newNode);
	
	
	cout << endl << "Using recursive reverse LLpairs" << endl;
	newNode = ReverseLLinPairsRecursive(newNode);
	printLL(newNode);
	
	
	
}