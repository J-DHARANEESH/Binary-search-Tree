
#include <iostream>
using namespace std;
// Definition of Node for Binary search tree
struct BstNode
{
	int data;
	BstNode *left;
	BstNode *right;
};

// Function to create a new Node in heap
BstNode *GetNewNode(int data)
{
	BstNode *newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
BstNode *Insert(BstNode *root, int data)
{
	if (root == NULL)
	{ // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	// else, insert in right subtree.
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}
// To search an element in BST, returns true if element is found
bool Search(BstNode *root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}
int main()
{
	BstNode *root = NULL; // Creating an empty tree
	int c, e;

	do
	{
		cout << "1.Insert\n";
		cout << "2.Search\n";
		cout << "3.Exit\n";
		cout << "Enter your choice : ";
		cin >> c;
		switch (c)
		{

		case 1:
			cout << "Enter the element: ";
			cin >> e;
			root = Insert(root, e);
			break;
		case 2:
			// Ask user to enter a number.
			int number;
			cout << "Enter number be searched\n";
			cin >> number;
			// If number is found, print "FOUND"
			if (Search(root, number) == true)
				cout << "Found\n";
			else
				cout << "Not Found\n";
			break;
		case 3:
			break;

		default:
			cout << "Wrong choice\n";
		};
	} while (c != 3);
	return 0;
};