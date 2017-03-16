/*
 * BinaryTree.h
 *
 *  Created on: Mar 16, 2017
 *      Author: SebLkMa
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

struct BNode
{
	int keyValue;
	BNode* pLeft;
	BNode* pRight;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	BinaryTree(const BinaryTree& other) = delete; // no copy
	BinaryTree& operator=(const BinaryTree& other) = delete; // no assignment

	void insert(int newKey);
	BNode* search(int key);
	void destroyTree();

private:
	void destroyTree(BNode* pLeaf);
	void insert(int newKey, BNode* pLeaf);
	BNode* search(int key, BNode* pLeaf);

	BNode* pRoot;
};

#endif /* BINARYTREE_H_ */
