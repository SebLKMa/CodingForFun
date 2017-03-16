/*
 * BinaryTree.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: SebLkMa
 */
#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	cout << "BinaryTree::BinaryTree()" << endl;
	pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	cout << "BinaryTree::~BinaryTree()" << endl;
	destroyTree();
}

void BinaryTree::insert(int newKey)
{
	if (pRoot != nullptr) // b-tree is not empty
	{
		insert(newKey, pRoot); // calls recursive insert function
	}
	else // b-tree is empty, newKey would be in first root node
	{
		pRoot = new BNode();
		pRoot->keyValue = newKey;
		pRoot->pLeft = nullptr;
		pRoot->pRight = nullptr;
	}
}

BNode* BinaryTree::search(int key)
{
	return search(key, pRoot);
}

void BinaryTree::destroyTree()
{
	destroyTree(pRoot);
}

void BinaryTree::insert(int newKey, BNode* pLeaf)
{
	// recursively inserts the newKey in the correct location of this b-tree
	if (newKey < pLeaf->keyValue)
	{
		if (pLeaf->pLeft != nullptr)
		{
			insert(newKey, pLeaf->pLeft);
		}
		else
		{
			pLeaf->pLeft = new BNode();
			pLeaf->pLeft->keyValue = newKey;
			pLeaf->pLeft->pLeft = nullptr;
			pLeaf->pLeft->pRight = nullptr;
		}
	}
	if (newKey >= pLeaf->keyValue)
	{
		if (pLeaf->pRight != nullptr)
		{
			insert(newKey, pLeaf->pRight);
		}
		else
		{
			pLeaf->pRight = new BNode();
			pLeaf->pRight->keyValue = newKey;
			pLeaf->pRight->pLeft = nullptr;
			pLeaf->pRight->pRight = nullptr;
		}
	}
}

BNode* BinaryTree::search(int key, BNode* pLeaf)
{
	if (pLeaf != nullptr)
	{
		if (key == pLeaf->keyValue)
		{
			return pLeaf; // node found
		}

		if (key < pLeaf->keyValue)
		{
			search(key, pLeaf->pLeft);
		}
		else
		{
			search(key, pLeaf->pRight);
		}
	}

	return nullptr; // reaching here means not found
}

void BinaryTree::destroyTree(BNode* pLeaf)
{
	if (pLeaf != nullptr)
	{
		destroyTree(pLeaf->pLeft);
		destroyTree(pLeaf->pRight);
		cout << "deleting node " << pLeaf->keyValue << endl;
		delete pLeaf;
	}
}

