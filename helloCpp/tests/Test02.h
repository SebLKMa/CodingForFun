/*
 * Test02.h
 *
 *  Created on: Jan 4, 2017
 *      Author: LMA
 */

#ifndef TEST02_H_
#define TEST02_H_
#include <memory>

class Base; // forward declaration

class Test02
{
public:
	void testInheritanceInStack();
	void testInheritanceInHeap();
	void testInheritanceInHeap2();
	void testCpp11unique_ptr();
	void testCpp11unique_ptr_Move();
	void testCpp11shared_ptr2(std::shared_ptr<Base> pBase);
	void testCpp11shared_ptr1();
	void testCpp11();
	void testCopy();
	void testAssignment();
	void testMove();
	void testCopyAssign();
};


#endif /* TEST02_H_ */
