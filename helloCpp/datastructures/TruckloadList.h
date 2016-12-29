/*
 * TruckloadList.h
 *
 *  Created on: Dec 28, 2016
 *      Author: LMA
 */

#ifndef TRUCKLOADLIST_H_
#define TRUCKLOADLIST_H_

#include "PackageNode.h"

/**
 * TruckloadList is a linkedlist of PackageNode objects.
 */
class TruckloadList
{
public:
	TruckloadList() {}

	// ctor, first node
	TruckloadList(std::shared_ptr<Box> pBox);
	/*
	{
		pHead = pTail = std::make_shared<PackageNode>(pBox);
	}*/

	// ctor, vector of boxes
	TruckloadList(const std::vector< std::shared_ptr<Box> >& boxes);

	std::shared_ptr<Box> getFirstBox();

	std::shared_ptr<Box> getNextBox();

	void addBox(std::shared_ptr<Box> pBox);

	void deleteBox(std::shared_ptr<Box> pBox);

	void listBoxes();

private:
	std::shared_ptr<PackageNode> pHead;
	std::shared_ptr<PackageNode> pTail;
	std::shared_ptr<PackageNode> pCurrent; // the last retrieved
	size_t m_Size{};
};

#endif /* TRUCKLOADLIST_H_ */
