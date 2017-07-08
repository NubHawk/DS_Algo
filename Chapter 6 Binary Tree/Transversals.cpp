#include <iostream>
#include <cstdlib>

using namespace std;

struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

//recursive transversals

void PreOrder(struct BinaryTree *root)
{
	if(root)
	{
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
		
	}
}

void InOrder(struct BinaryTree *root)
{
	if(root)
	{
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
		
	}
}

void PostOrder(struct BinaryTree *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	
		
	}
}

//non recursive transversals
#include <stack>


void PreOrderNonRecursive(struct BinaryTree *root)
{
	stack<struct BinaryTree *> S;
	
	while(true)
	{
		while(root)
		{
			cout << root->data << " ";
			S.push(root);
			root = root->left;
		}
		
		//after exiting root == NULL
		if(S.empty())
			break;
		root = S.top();
		S.pop();
		root = root->right;
	}
	
	cout << endl;
}

void InOrderNonRecursive(struct BinaryTree *root)
{
	stack<struct BinaryTree *> S;
	while(true)
	{
		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty())
			break;
		root = S.top();
		S.pop();
		cout << root->data << " ";
		root = root->right;
	}
	cout << endl;
}

void PostOrderNonRecursive(struct BinaryTree *root)
{
	stack<struct BinaryTree *> S;
	
	while(true)
	{
		while(root)
		{
			S.push(root);
			root = root->left;
		}
		root = S.top();
		S.pop();
		root = root->right;
	}
}




int main()
{
	struct BinaryTree *bt = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
	bt->data = 1;
	bt->left = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
	bt->left->data = 2;
	bt->right = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
	bt->right->data = 3;
	bt->left->left = NULL;
	bt->left->right = NULL;
	bt->right->left = NULL;
	bt->right->right = NULL;
	
	cout << "PreOrder transversal" << endl;
	PreOrder(bt);
	cout << endl;
	cout << "InOrder tranversal" << endl;
	InOrder(bt);
	cout << endl;
	cout << "PostOrder transversal" << endl;
	PostOrder(bt);
	cout << endl;
	cout << "PreOrder Non Recursive transversal" << endl;
	PreOrderNonRecursive(bt);
	cout << "InOrder Non Recursive transversal" << endl;
	InOrderNonRecursive(bt);
	
	
	
}