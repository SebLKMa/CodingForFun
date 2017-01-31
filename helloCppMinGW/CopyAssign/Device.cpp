/*
 * Device.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: LMA
 */
#include "Device.h"

#include <iostream>
#include <cstring> // for strlen, strcpy

using namespace std;

Device::Device(const char* pName, unsigned int noOfStars) : m_NoOfStars{noOfStars}
{
	cout << "Device()" << endl;

	const unsigned int len = strlen(pName) + 1; // +1 for null terminator
	m_pName = new char[len]{};
	strcpy(m_pName, pName);
}

Device::~Device()
{
	cout << "~Device()" << endl;

	delete m_pName;
	m_pName = nullptr;
}

Device::Device(const Device& other)
{
	cout << "copy constructor" << endl;

	// allocate own storage
	const unsigned int len = strlen(other.m_pName) + 1; // +1 for null terminator
	m_pName = new char[len]{};
	strcpy(m_pName, other.m_pName);
	m_NoOfStars = other.m_NoOfStars;
}

Device& Device::operator=(const Device& other)
{
	cout << "assignment operator" << endl;

	if (this != &other) // prevent assign to self
	{
		// deallocate own storage
		if (m_pName != nullptr)
		{
			delete m_pName;
		}

		const unsigned int len = strlen(other.m_pName) + 1; // +1 for null terminator
		m_pName = new char[len]{};
		strcpy(m_pName, other.m_pName);
		m_NoOfStars = other.m_NoOfStars;
	}
	return *this;
}

char* Device::getName()
{
	return m_pName;
}

unsigned int Device::getNoOfStars()
{
	return m_NoOfStars;
}
