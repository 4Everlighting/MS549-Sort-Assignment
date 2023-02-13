
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

// Node structure
struct Node
{
	int key;
	int number;
	struct Node *left;
	struct Node *right;
}*root;

// Create the class
class binaryTree
{
public:
	void insert(Node *, Node *, int);
	void find(int, Node **, Node **);
	void findMax();
	void deleting(int);

	void noChildren(Node *, Node *);
	void oneChild(Node *, Node *);
	void twoChildren(Node *, Node *);

	void display(Node *, int);

	binaryTree() // Initiallizer
	{
		root = NULL;
	}
};

// Insert numbers into the tree
void binaryTree::insert(Node *tree, Node *newnode, int key)
{
	// Tree is empty == create root
	if (root == NULL)
	{
		root = new Node;
		root->number = newnode->number;
		root->key = key;
		root->left = NULL;
		root->right = NULL;

		cout << "Root Node has been added" << endl;
		return;
	}

	// If it's already in the tree
	if (tree->number == newnode->number)
	{
		cout << "That number is already in the tree" << endl;
		return;
	}

	// If the new number is smaller, add it to the left leg
	if (tree->number > newnode->number)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newnode, key);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->key = key;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;

			cout << "Node added to the left leg." << endl;
			return;
		}
	}
	// Otherwise add it to the right leg
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newnode, key);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->key = key;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;

			cout << "Node Added To Right" << endl;
			return;
		}
	}
}

// Find a number
void binaryTree::find(int item, Node **parent, Node **location)
{
	Node *legToFollow, *legSave;

	// If tree is empty, there's nothing to find
	if (root == NULL)
	{
		*location = NULL;
		*parent = NULL;
		return;
	}

	// If the root is the number
	if (item == root->number)
	{
		*location = root;
		*parent = NULL;
		return;
	}

	// Follow the left legs
	if (item < root->number)
	{
		legToFollow = root->left;
	}
	// Follow the right
	else
	{
		legToFollow = root->right;
	}

	legSave = root;

	// Keep following til found or the end
	while (legToFollow != NULL)
	{
		// If found
		if (item == legToFollow->number)
		{
			*location = legToFollow;
			*parent = legSave;
			return;
		}

		legSave = legToFollow;

		if (item < legToFollow->number)
		{
			legToFollow = legToFollow->left;
		}
		else
		{
			legToFollow = legToFollow->right;
		}
	}

	*location = NULL;
	*parent = legSave;

}

void binaryTree::findMax()
{
	Node *legToFollow, *legSave;

	// If tree is empty, there's nothing to find
	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}

	// If the root is the max key
	if (root->left == NULL && root->right == NULL)
	{
		cout << "The item with the maximum key is " << root->number << endl;
		return;
	}

	// Follow the left legs
	if (root->left->key > root->right->key)
	{
		legToFollow = root->left;
	}
	// Follow the right
	else
	{
		legToFollow = root->right;
	}

	legSave = root;

	// Keep following til found or the end
	while (legToFollow != NULL)
	{
		// If found
		if (legToFollow->left == NULL && legToFollow->right == NULL)
		{
			cout << "The item with the maximum key is " << legToFollow->number << endl;
			return;
		}

		legSave = legToFollow;

		if (legToFollow->left->key > legToFollow->right->key)
		{
			legToFollow = legToFollow->left;
		}
		else
		{
			legToFollow = legToFollow->right;
		}
	}
}

// Deleting numbers
void binaryTree::deleting(int item)
{
	Node *parent, *location;

	// If the tree is empty
	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}

	// Find the number to delete
	find(item, &parent, &location);

	// If not found
	if (location == NULL)
	{
		cout << "That number could not be found" << endl;
		return;
	}

	// No Children
	if (location->left == NULL && location->right == NULL)
	{
		noChildren(parent, location);
	}

	// One Child
	if (location->left != NULL && location->right == NULL || location->left == NULL && location->right != NULL)
	{
		oneChild(parent, location);
	}

	// Two Children
	if (location->left != NULL && location->right != NULL)
	{
		twoChildren(parent, location);
	}

	free(location);

}

void binaryTree::noChildren(Node *parent, Node *location)
{
	// delete the root
	if (parent == NULL)
	{
		root = NULL;
	}
	// Delete the number
	else
	{
		if (location == parent->left)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
}

void binaryTree::oneChild(Node *parent, Node *location)
{
	Node *child;

	// Move the location of the child to the left or right node (where parent was)
	if (location->left != NULL)
	{
		child = location->left;
	}
	else
	{
		child = location->right;
	}

	// Make the root the child
	if (parent == NULL)
	{
		root = child;
	}

	// Move the parent of the child to the left or right node (where the parent's parent was)
	else
	{
		if (location == parent->left)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
	}
}

void binaryTree::twoChildren(Node *parent, Node *location)
{
	Node *following, *saveLoc, *suc, *parsuc;

	saveLoc = location;
	following = location->right;

	// While there's something to follow
	while (following->left != NULL)
	{
		saveLoc = following;
		following = following->left;
	}

	suc = following; // save follow spot
	parsuc = saveLoc; // save the location

					  // If both legs are null do no children deletion
	if (suc->left == NULL && suc->right == NULL)
	{
		noChildren(parsuc, suc);
	}
	else // One child deletion
	{
		oneChild(parsuc, suc);
	}

	// No parent = root
	if (parent == NULL)
	{
		root = suc;
	}
	// Move the children
	else
	{
		if (location == parent->left)
		{
			parent->left = suc;
		}
		else
		{
			parent->right = suc;
		}
	}

	suc->left = location->left;
	suc->right = location->right;
}

// Display the tree
void binaryTree::display(Node *ptr, int level)
{
	int i;

	// Until everything has been displayed, show it as either left or right legs.
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;

		if (ptr == root)
		{
			cout << "Root->:  ";
		}
		else
		{
			for (i = 0; i < level; i++)
			{
				cout << "       ";
			}
		}

		cout << ptr->number;
		display(ptr->left, level + 1);
	}
}

// Main Program
int main()

{
	binaryTree tree;
	binaryTree tree100;
	binaryTree tree1000;
	binaryTree tree10000;
	binaryTree tree100000;

	/* Adding 100 nodes to the tree
	int arr [100];
	clock_t start;
	clock_t end;
	start = clock();
	srand(2);
	for (int i=0; i < 100; i++)
	{ 
		arr[i] = rand();
		Node *temp = new Node;
		temp->number = arr[i];
		tree100.insert(root, temp, i);
	}
	end = clock();
	cout << endl << "100 nodes added." << endl;
	cout<< "time it takes for each number of add calls " << (end-start) << endl;
	tree100.display(root, 1);

	//tree100.findMax();
	system("pause");
	
	// Deleting 100 nodes from the tree
	start = clock();
	for (int j = 0; j < 100; j++)
	{ 
		tree100.deleting(arr[j]); 
	}
	end = clock();
	cout << endl << "100 nodes deleted." << endl;
	cout << "time it takes for each number of remove calls " << (end - start) << endl;
	tree100.display(root, 1);
	system("pause");
	*/
	/* Adding 1000 nodes to the tree
	int arr [1000];
	clock_t start;
	clock_t end;
	start = clock();
	srand(3);
	for (int i = 0; i < 1000; i++)
	{ 
		arr[i] = rand();
		Node *temp = new Node;
		temp->number = arr[i];
		tree1000.insert(root, temp, i); 
	}
	end = clock();
	cout << endl << "1000 nodes added." << endl;
	cout<< "time it takes for each number of add calls " << (end-start) << endl;
	system("pause");

	// Deleting 1000 nodes from the tree
	for (int j = 0; j < 1000; j++)
	{ 
		tree1000.deleting(arr[j]); 
	}
	end = clock();
	cout << endl << "1000 nodes deleted." << endl;
	cout << "time it takes for each number of remove calls " << (end - start) << endl;
	system("pause");
	*/
	/*
	//Adding 10000 nodes to the tree
	int arr [10000];
	clock_t start;
	clock_t end;
	start = clock();
	srand(4);
	for (int i = 0; i < 10000; i++)
	{ 
		arr[i] = rand();
		Node *temp = new Node;
		temp->number = arr[i];
		tree10000.insert(root, temp, i); 
	}
	end = clock();
	cout << endl << "10000 nodes added." << endl;
	cout << "time it takes for each number of add calls " << (end - start) << endl;
	system("pause");

	// Deleting 10000 nodes from the tree
	start = clock();
	for (int j = 0; j < 10000; j++)
	{ 
		tree10000.deleting(j); 
	}
	end = clock();
	cout << endl << "time it takes for each number of remove calls " << (end - start) << endl;
	system("pause");
	*/
	// Adding 100000 nodes to the tree
	int arr[100000];
	clock_t start;
	clock_t end;
	start = clock();
	for (int i = 0; i < 100000; i++)
	{ 
		arr[i] = rand();
		Node *temp = new Node;
		temp->number = arr[i];
		tree100000.insert(root, temp, 1); 
	}
	end = clock();
	cout << endl << "100000 nodes added." << endl;
	cout << "time it takes for each number of add calls " << (end - start) << endl;
	//tree10000.findmax();
	system("pause");
	// Deleting 100000 nodes from the tree
	start = clock();
	for (int j = 0; j < 100000; j++)
	{ 
		tree100000.deleting(j); 
	}
	end = clock();
	cout << endl << "100000 nodes deleted." << endl;
	cout << "time it takes for each number of remove calls " << (end - start) << endl;
	system("pause");
	return 0;
}
