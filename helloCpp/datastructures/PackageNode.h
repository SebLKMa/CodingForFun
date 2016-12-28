/*
 * Package.h
 *
 *  Created on: Dec 28, 2016
 *      Author: LMA
 */

#ifndef PACKAGENODE_H_
#define PACKAGENODE_H_

#include <memory>
#include "..\Box.h"

/**
 * PackageNode is linked node of Box object using ref-counted pointer shared_ptr
 */
class PackageNode
{
public:
	// ctor
	PackageNode(std::shared_ptr<Box> pB) : pBox{pB}, pNext{} {}

	std::shared_ptr<Box>& getBox() { return pBox; }

	std::shared_ptr<PackageNode>& getNext() { return pNext; }

	void setNext(std::shared_ptr<PackageNode>& pPackageNode)
	{
		pNext = pPackageNode;
	}

private:
	std::shared_ptr<Box> pBox;
	std::shared_ptr<PackageNode> pNext;
};



#endif /* PACKAGENODE_H_ */
