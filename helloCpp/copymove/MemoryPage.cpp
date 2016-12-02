/*
 * MemoryPage.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: LMA
 */
#include <iostream>
#include "string.h"
#include "MemoryPage.h"

using namespace std;

/**
 *  For copy and assigment
 *  http://www.keithschwarz.com/cs106l/winter20072008/handouts/170_Copy_Constructor_Assignment_Operator.pdf
 Theorem: If a class has any of the following three member functions:
 - Destructor
 - Copy Constructor
 - Assignment Operator
 Then that class should have all three of those functions.
 Corollary: If a class has a destructor, it should also have a copy constructor and assignment operator.

 *  For move
 *  http://blog.smartbear.com/c-plus-plus/c11-tutorial-introducing-the-move-constructor-and-the-move-assignment-operator/
The state of a moved-from object is unspecified.
Therefore, always assume that a moved-from object no longer owns any resources,
and that its state is similar to that of an empty (as if default-constructed) object.
For example, if you move a string s1 to s2, after the move operation the state of s2
is identical to that of s1 before the move, whereas s1 is now an empty (though valid)
string object.

 */

MemoryPage::MemoryPage(int sz) : m_Size(sz), m_pBuf(new char[m_Size])
{
	logMessage("MemoryPage");
}

MemoryPage::~MemoryPage()
{
	clear();
	logMessage("~MemoryPage");
}

// typical C++ copy ctor
MemoryPage::MemoryPage(const MemoryPage& other)
{
	// codes as copy ctor
	copyOther(other);
	logMessage("MemoryPage copy ctor");
}

// typical C++ assignment operator
MemoryPage& MemoryPage::operator=(const MemoryPage& other)
{
	if (this != &other) // prevent assignment to self
	{
		// MUST first de-allocate current
		clear();

		// codes as copy ctor
		copyOther(other);
	}

	logMessage("MemoryPage assignment operator");
	return *this;
}

// C++11 move ctor &&
// move is faster, it does not need to allocate nor deep-copy memory buffer
MemoryPage::MemoryPage(MemoryPage&& other)
{
	// pilfer other's resources
	m_Size = other.m_Size;
	m_pBuf = other.m_pBuf;

	// reset on other
	other.m_Size = 0;
	other.m_pBuf = nullptr;

	logMessage("MemoryPage move ctor");
}

// C++11 move assignment &&
// A move assignment operator is similar to a copy constructor except that before
// pilfering the source object, it releases any resources that its object may own.
MemoryPage& MemoryPage::operator=(MemoryPage&& other)
{
	if (this != &other) // prevent assignment to self
	{
		// release current object's resources
		clear();

		// pilfer other's resources
		m_Size = other.m_Size;
		m_pBuf = other.m_pBuf;

		// reset on other
		other.m_Size = 0;
		other.m_pBuf = nullptr;
	}
	logMessage("MemoryPage move assignment operator");
	return *this;
}

void MemoryPage::copyOther(const MemoryPage& other)
{
	// codes as copy ctor
	m_Size = other.m_Size;
	m_pBuf = new char[m_Size];
	for (size_t i = 0; i<m_Size; i++)
	{
		m_pBuf[i] = other.m_pBuf[i];
	}
}

/*
void MemoryPage::pilferOther(MemoryPage&& other)
{
	// pilfer other's resources
	m_Size = other.m_Size;
	m_pBuf = other.m_pBuf;

	// reset on other
	other.m_Size = 0;
	other.m_pBuf = nullptr;
}
*/

void MemoryPage::clear()
{
	delete [] m_pBuf;
	m_pBuf = nullptr;
	m_Size = 0;
}

void MemoryPage::logMessage(const std::string& msg)
{
	time_t now;
	time(&now);
	char* ctime_str = ctime(&now);
	ctime_str[ strlen(ctime_str) - 1 ] = '\0'; // replaces last newline chr with null-termination

	cout << ctime_str << ":" << msg << endl;
}


