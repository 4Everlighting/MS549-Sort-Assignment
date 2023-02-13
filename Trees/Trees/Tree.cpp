#include "TreeNodeStructure.h"
#include "TreeNodeFactory.h"
#include <string.h>
#include <iostream>
using namespace std;



void main()
{
	cout << "\n\nWelcome to treeland in C++, we are going to build a tree out of nodes";

	// Build the tree using tree factory
	TreeNodeFactory* ptrTreeNodeFactory;
	TreeNodeStructure* ptrRootNode;
	ptrTreeNodeFactory->BuildTreeInsertNodes(ptrTreeNodeFactory, ptrRootNode);

	// Print out nodes using print factory
	ptrTreeNodeFactory->DisplayNodes(ptrRootNode);

	system("pause");

}
