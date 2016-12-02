/*
 * MemoryPage.h
 *
 *  Created on: Dec 1, 2016
 *      Author: LMA
 */

#ifndef MEMORYPAGE_H_
#define MEMORYPAGE_H_
#include <string>

class MemoryPage
{
public:
	explicit MemoryPage(int sz=512);
	~MemoryPage();

	// typical C++ copy ctor
	MemoryPage(const MemoryPage&);

	// typical C++ assignment operator
	MemoryPage& operator=(const MemoryPage&);

	// C++11 move ctor &&
	MemoryPage(MemoryPage&&);

	// C++11 move assignment &&
	MemoryPage& operator=(MemoryPage&&);

	size_t getSize() { return m_Size; }

protected:
	void logMessage(const std::string&);
	void copyOther(const MemoryPage&);
	void clear();

private:
	size_t m_Size;
	char* m_pBuf;
};


#endif /* MEMORYPAGE_H_ */
