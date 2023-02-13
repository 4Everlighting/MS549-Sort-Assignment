#include "TreeNodeFactory.h"
#include "TreeNodeStructure.h"
#include <iostream>
using namespace std;


void TreeNodeFactory::DisplayNodes(TreeNodeStructure* ptrRootNode)
{

	system("pause");
	cout << "\n\n\n\t\t     " << ptrRootNode->data << endl;
	cout << "\t\t   /   \\" << endl;
	cout << "\t\t  /     \\" << endl;
	// Level 2
	cout << "\t\t" << ptrRootNode->leftChild->data << "\t" << ptrRootNode->rightChild->data << endl;
	cout << "\t\t/ \\    " << "\t/ \\" << endl;
	// Level 3
	cout << "\t       " << ptrRootNode->leftChild->leftChild->data << "  " << ptrRootNode->leftChild->rightChild->data;
	cout << "\t";
	std::cout << ptrRootNode->rightChild->leftChild->data << " " << ptrRootNode->rightChild->rightChild->data << "\n\n\n";
}


TreeNodeStructure * TreeNodeFactory::SearchMyTree(TreeNodeStructure* rootNodeOfTree, int data)
{
	TreeNodeStructure * ptrResult = nullptr;

	// Check if the tree is empty
	if (rootNodeOfTree == nullptr)
	{
		ptrResult = nullptr;
	}
	// Search tree by level
	return ptrResult;
}

void TreeNodeFactory::BuildTreeInsertNodes(TreeNodeFactory*& ptrTreeNodeFactory, TreeNodeStructure*& ptrRootNode)
{
	cout << "\n\nStarting Build process....\n\n";
	cout << "Data values to use for our nodes to build our tree:\n";
	cout << "[25, 15, 35, 8, 20, 30, 45]\n\n";
	ptrTreeNodeFactory = new TreeNodeFactory();
	cout << "\n Adding 25\n";
	ptrRootNode = ptrTreeNodeFactory->CreateNewTreeNode(25);
	cout << "\n Adding 15\n";
	ptrRootNode->leftChild = ptrTreeNodeFactory->CreateNewTreeNode(15);
	cout << "\n Adding 35\n";
	ptrRootNode->rightChild = ptrTreeNodeFactory->CreateNewTreeNode(35);
	cout << "\n Adding 8\n";
	ptrRootNode->leftChild->leftChild = ptrTreeNodeFactory->CreateNewTreeNode(8);
	cout << "\n Adding 20\n";
	ptrRootNode->leftChild->rightChild = ptrTreeNodeFactory->CreateNewTreeNode(20);
	cout << "\n Adding 30\n";
	ptrRootNode->rightChild->leftChild = ptrTreeNodeFactory->CreateNewTreeNode(30);
	cout << "\n Adding 45\n";
	ptrRootNode->rightChild->rightChild = ptrTreeNodeFactory->CreateNewTreeNode(45);
	cout << "\n *** All nodes have been added, tree has been built ***\n";
}


TreeNodeStructure* TreeNodeFactory::CreateNewTreeNode(int data)
{
	TreeNodeStructure *treeNodeStructure = new TreeNodeStructure();
	// set data value for node to hold
	treeNodeStructure->data = data;
	// set left child node to null for creation until we 
	// determine which type of node this will be based on
	// node position
	treeNodeStructure->leftChild = nullptr;
	treeNodeStructure->rightChild = nullptr;	

	return treeNodeStructure;	
}


