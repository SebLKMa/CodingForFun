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

void MemoryPage::clear()
{
	delete [] m_pBuf;
	m_pBuf = 0;
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


