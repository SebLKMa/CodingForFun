/*
 * Test03.cpp
 *
 *  Created on: Jan 5, 2017
 *      Author: LMA
 */
#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <vector>
#include "Test03.h"
#include "..\HelloContainers.h"
#include "..\datastructures\TruckloadList.h"
#include "..\Box.h"
#include "..\datastructures\BinaryTree.h"

using namespace std;

Test03::Test03()
{
	cout << "Test03::Test03()" << endl;
}

void Test03::testTruckloadList()
{
	const size_t dimLimit {99}; // upper limit on Box dimensions
	std::srand((unsigned)std::time(0)); // initialize random number generator

	TruckloadList list1;
	// add 12 random boxes to list
	const size_t boxCount {12};
	for (size_t i{}; i<boxCount; ++i)
	{
		list1.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}
	cout << "The first list:\n";
	list1.listBoxes();

	// Find the largest Box in the list
	shared_ptr<Box> pBox {list1.getFirstBox()};
	shared_ptr<Box> pNextBox {};
	while (pNextBox = list1.getNextBox()) // assign then test to next Box
	{
		if (pBox->compare(*pNextBox) < 0)
			pBox = pNextBox;
	}
	cout << "\nThe largest box in the first list is:";
	pBox->listBox();
	cout << endl;
	list1.deleteBox(pBox);
	cout << "\nAfter deleting the largest box, the list contains:\n";
	list1.listBoxes();

	const size_t NBOXES{20};
	vector<shared_ptr<Box>> boxes;
	for (size_t i{}; i<NBOXES; ++i)
	{
		boxes.push_back(make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}

	TruckloadList list2(boxes);
	cout << "\nThe second list:\n";
	list2.listBoxes();

	pBox = list2.getFirstBox();
	while (pNextBox = list2.getNextBox())
	{
		if (pBox->compare(*pNextBox) > 0)
		{
			pBox = pNextBox;
		}
	}

	cout << "\nThe smallest box in the first list is:";
	pBox->listBox();
	cout << endl;
}

void Test03::testBinaryTree()
{
	// unique_ptr is a smart pointer that owns the object.
	// object will be deleted when goes out of scope.
	unique_ptr<BinaryTree> pTree(new BinaryTree);
	pTree->insert(10);
	pTree->insert(6);
	pTree->insert(14);
	pTree->insert(5);
	pTree->insert(8);
	pTree->insert(11);
	pTree->insert(18);

	int value = 8;
	BNode* pNode = pTree->search(value);
	if (pNode == nullptr)
	{
		cout << "Binary node not found for value " << value << endl;
	}
	else
	{
		cout << "Binary node found for value: " << pNode->keyValue << endl;
	}
	value = 42;
	pNode = pTree->search(value);
	if (pNode == nullptr)
	{
		cout << "Binary node not found for value " << value << endl;
	}
	else
	{
		cout << "Binary node found for value: " << pNode->keyValue << endl;
	}
}
/*
void Test02::testCpp11unique_ptr_Move()
{
	unique_ptr<DerivedA> pA(new DerivedA);   // pA owns DerivedA
	pA->sayHi();
	unique_ptr<DerivedA> pB = std::move(pA); // passes ownership to pB
	pB->sayHi();
}
*/
