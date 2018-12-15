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
	pRoot = nullptr;
	cout << "BinaryTree::BinaryTree()" << endl;
}

BinaryTree::~BinaryTree()
{
	cout << "BinaryTree::~BinaryTree() begin" << endl;
	destroyTree();
	cout << "BinaryTree::~BinaryTree() end" << endl;
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
	// based on value is greater or less than current node
	// recursively inserts the newKey on the left side or right side of b-tree

	if (newKey < pLeaf->keyValue)
	{
		if (pLeaf->pLeft == nullptr) // if left ptr is empty, set new Node to it
		{
			pLeaf->pLeft = new BNode();
			pLeaf->pLeft->keyValue = newKey;
			pLeaf->pLeft->pLeft = nullptr;
			pLeaf->pLeft->pRight = nullptr;
		}
		else                        // otherwise continue on the left side
		{
			insert(newKey, pLeaf->pLeft);
		}
	}
	if (newKey >= pLeaf->keyValue)
	{
		if (pLeaf->pRight == nullptr) // if right ptr is empty, set new Node to it
		{
			pLeaf->pRight = new BNode();
			pLeaf->pRight->keyValue = newKey;
			pLeaf->pRight->pLeft = nullptr;
			pLeaf->pRight->pRight = nullptr;
		}
		else                         // otherwise continue on the right side
		{
			insert(newKey, pLeaf->pRight);
		}
	}
}

// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//
BNode* BinaryTree::search(int key, BNode* pLeaf)
{
	if (pLeaf == nullptr)
	{
		// reaching here means we found nothing
		return pLeaf;
	}

	cout << "Searching for " << key << "...Current node value: " << pLeaf->keyValue << endl;
	// based on value is greater or less than current node
	// recursively search the left side or right side of b-tree

	if (key == pLeaf->keyValue)
	{
		cout << "Search found at node value: " << pLeaf->keyValue << endl;
		return pLeaf; // node found
	}

	if (key < pLeaf->keyValue)
	{
		return search(key, pLeaf->pLeft);
	}

	return search(key, pLeaf->pRight);
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

