

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

void inorder(BstNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

int minimum_val(struct BstNode *BstNode)
{
	struct BstNode *cur = BstNode;
	while (cur->left != NULL)
	{
		cur = cur->left;
	}
	return (cur->data);
}

int main()
{
	BstNode *root = NULL;
	int c, e;
	string b;
	// bool r;

	do
	{
		cout << "\n1.Insert\n";
		cout << "2.Search\n";
		cout << "3.Display\n";
		cout << "4.Min Value\n";
		cout << "5.Exit\n";
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

			int number;
			cout << "Enter number be searched\n";
			cin >> number;
			// r=Search(root,number);

			// cout<< r;
			//  If number is found, print "FOUND"
			if (Search(root, number) == true)
				cout << "Found\n";
			else
				cout << "Not Found\n";
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			cout << minimum_val(root);
			break;
		case 5:
			break;

		default:
			cout << "Wrong choice\n";
		};
	} while (c != 5);
	return 0;
};
