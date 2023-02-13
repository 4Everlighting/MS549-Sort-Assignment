#pragma once
#include "TreeNodeStructure.h"


class TreeNodeFactory
{
public:

	void BuildTreeInsertNodes(TreeNodeFactory*& ptrTreeNodeFactory, TreeNodeStructure*& ptrRootNode);
	TreeNodeStructure * CreateNewTreeNode(int data);
	TreeNodeStructure * SearchMyTree(TreeNodeStructure* rootNodeOfTree, int data);
	void DisplayNodes(TreeNodeStructure* ptrRootNode);

};
