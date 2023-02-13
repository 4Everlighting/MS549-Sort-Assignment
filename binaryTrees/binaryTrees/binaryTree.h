#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

// Structure for nodes
struct node

{

	int info;

	struct node *left;

	struct node *right;

}*root;

// Create the class
class binaryTree
{

public:

	void find(int, node **, node **);

	void insert(node *, node *);

	void del(int);

	void case_a(node *, node *);

	void case_b(node *, node *);

	void case_c(node *, node *);

	void display(node *, int);

	binaryTree()

	{

		root = NULL;

	}

};