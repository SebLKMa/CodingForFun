/*
 * TruckloadList.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: LMA
 */

#include <memory>
#include <vector>
#include <iostream>
#include "..\Box.h"
#include "PackageNode.h"
#include "TruckloadList.h"


TruckloadList::TruckloadList(std::shared_ptr<Box> pBox)
{
	// use make_shared for exception safety and leak prevention.
	// e.g. foo(std::shared_ptr<SomeObject>(new SomeObject()), thrower())
	// memory leak can occur if thrower() throws, new SomeObject() already executed
	pHead = pTail = std::make_shared<PackageNode>(pBox);
	++m_Size;
}

TruckloadList::TruckloadList(const std::vector< std::shared_ptr<Box> >& boxes)
{
	for (auto pBox : boxes)
	{
		addBox(pBox);
	}
}

void TruckloadList::addBox(std::shared_ptr<Box> pBox)
{
	auto pNode = std::make_shared<PackageNode>(pBox);

	if (pHead)					// if our list is not empty, append to tail
		pTail->setNext(pNode);
	else
		pHead = pNode;			// else add to head

	pTail = pNode;				// set added node to tail
	++m_Size;
}

std::shared_ptr<Box> TruckloadList::getFirstBox()
{
	pCurrent = pHead->getNext(); // move current to next
	return pHead->getBox();
}

void TruckloadList::deleteBox(std::shared_ptr<Box> pBox)
{
	auto pPrevious = pHead;
	pCurrent = pHead; // start from the first
	for (size_t i{}; i<m_Size; ++i)
	{
		if (pCurrent->getBox() == pBox)
		{
			pPrevious->setNext(pCurrent->getNext());
			--m_Size;
			break;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->getNext();
	}
}

std::shared_ptr<Box> TruckloadList::getNextBox()
{
	if (!pCurrent) // nothing in current yet, return the first
		return getFirstBox();

	auto pNode = pCurrent->getNext();
	if (pNode)
	{
		pCurrent = pNode;
		return pNode->getBox();
	}

	// otherwise, there is no next
	pCurrent = nullptr;
	return nullptr;
}

void TruckloadList::listBoxes()
{
	pCurrent = pHead; // start from the first
	size_t count {};
	while (pCurrent)
	{
		pCurrent->getBox()->listBox();
		pCurrent = pCurrent->getNext();
		if (!(++count % 5)) std::cout << std::endl;
	}
	if (count % 5) std::cout << std::endl;
}

