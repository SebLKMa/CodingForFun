/*
 * Test01.h
 *
 *  Created on: Jan 4, 2017
 *      Author: LMA
 */

#ifndef TEST01_H_
#define TEST01_H_
#include <string>

class Test01
{
public:
	void testStringTypes();
	void testStringUtils();
	void testPtrsBasics();
	void testRefsBasics();
	void testLoops();
	void testArraySorter();
	void testQuicksort();
	void testFileIO();
	void testTArray1();
	void testTArray2();
	void testByteOrder();
	void testBitShift();
	void testBitMasks();
	void testIsSameClass();

private:
	void checkUserPermission(const std::string& userId, const unsigned short& userPermission);
	void setUserPermission(unsigned short& userPermission, const unsigned short& setPermission);
	void unsetUserPermission(unsigned short& userPermission, const unsigned short& unsetPermission);
};

#endif /* TEST01_H_ */
