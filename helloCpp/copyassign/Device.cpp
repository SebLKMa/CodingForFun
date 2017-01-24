/*
 * Device.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: LMA
 */
#include <iostream>
#include <cstring> // for strlen, strcpy
#include "Device.h"

using namespace std;

Device::Device(const char* pName, size_t noOfStars) : m_NoOfStars{noOfStars}
{
	cout << "Device()" << endl;

	const size_t len = strlen(pName) + 1; // +1 for null terminator
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
	const size_t len = strlen(other.m_pName) + 1; // +1 for null terminator
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

		const size_t len = strlen(other.m_pName) + 1; // +1 for null terminator
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

size_t Device::getNoOfStars()
{
	return m_NoOfStars;
}
