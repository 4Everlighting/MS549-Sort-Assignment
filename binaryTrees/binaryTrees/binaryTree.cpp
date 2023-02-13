#include "binaryTree.h"

// Find in the tree
void binaryTree::find(int item, node **par, node **loc)

{

	node *ptr, *ptrsave;

	if (root == NULL)

	{

		*loc = NULL;

		*par = NULL;

		return;

	}

	if (item == root->info)

	{

		*loc = root;

		*par = NULL;

		return;

	}

	if (item < root->info)

		ptr = root->left;

	else

		ptr = root->right;

	ptrsave = root;

	while (ptr != NULL)

	{

		if (item == ptr->info)

		{

			*loc = ptr;

			*par = ptrsave;

			return;

		}

		ptrsave = ptr;

		if (item < ptr->info)

			ptr = ptr->left;

		else

			ptr = ptr->right;

	}

	*loc = NULL;

	*par = ptrsave;

}

// Insert a value
void binaryTree::insert(node *tree, node *newnode)

{

	if (root == NULL)

	{

		root = new node;

		root->info = newnode->info;

		root->left = NULL;

		root->right = NULL;

		cout << "Root Node is Added" << endl;

		return;

	}

	if (tree->info == newnode->info)

	{

		cout << "Element already in the tree" << endl;

		return;

	}

	if (tree->info > newnode->info)

	{

		if (tree->left != NULL)

		{

			insert(tree->left, newnode);

		}

		else

		{

			tree->left = newnode;

			(tree->left)->left = NULL;

			(tree->left)->right = NULL;

			cout << "Node Added To Left" << endl;

			return;

		}

	}

	else

	{

		if (tree->right != NULL)

		{

			insert(tree->right, newnode);

		}

		else

		{

			tree->right = newnode;

			(tree->right)->left = NULL;

			(tree->right)->right = NULL;

			cout << "Node Added To Right" << endl;

			return;

		}

	}

}

// Delete a value from the tree
void binaryTree::del(int item)

{

	node *parent, *location;

	if (root == NULL)

	{

		cout << "Tree empty" << endl;

		return;

	}

	find(item, &parent, &location);

	if (location == NULL)

	{

		cout << "Item not present in tree" << endl;

		return;

	}

	if (location->left == NULL && location->right == NULL)

		case_a(parent, location);

	if (location->left != NULL && location->right == NULL)

		case_b(parent, location);

	if (location->left == NULL && location->right != NULL)

		case_b(parent, location);

	if (location->left != NULL && location->right != NULL)

		case_c(parent, location);

	free(location);

}



// No children
void binaryTree::case_a(node *par, node *loc)

{

	if (par == NULL)

	{

		root = NULL;

	}

	else

	{

		if (loc == par->left)

			par->left = NULL;

		else

			par->right = NULL;

	}

}



// One child
void binaryTree::case_b(node *par, node *loc)

{

	node *child;

	if (loc->left != NULL)

		child = loc->left;

	else

		child = loc->right;

	if (par == NULL)

	{

		root = child;

	}

	else

	{

		if (loc == par->left)

			par->left = child;

		else

			par->right = child;

	}

}



// Two children
void binaryTree::case_c(node *par, node *loc)

{

	node *ptr, *ptrsave, *suc, *parsuc;

	ptrsave = loc;

	ptr = loc->right;

	while (ptr->left != NULL)

	{

		ptrsave = ptr;

		ptr = ptr->left;

	}

	suc = ptr;

	parsuc = ptrsave;

	if (suc->left == NULL && suc->right == NULL)

		case_a(parsuc, suc);

	else

		case_b(parsuc, suc);

	if (par == NULL)

	{

		root = suc;

	}

	else

	{

		if (loc == par->left)

			par->left = suc;

		else

			par->right = suc;

	}

	suc->left = loc->left;

	suc->right = loc->right;

}

// Display Tree Structure
void binaryTree::display(node *ptr, int level)

{

	int i;

	if (ptr != NULL)

	{

		display(ptr->right, level + 1);

		cout << endl;

		if (ptr == root)

			cout << "Root->:  ";

		else

		{

			for (i = 0; i < level; i++)

				cout << "       ";

		}

		cout << ptr->info;

		display(ptr->left, level + 1);

	}

}