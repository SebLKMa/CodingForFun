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

using namespace std;

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



