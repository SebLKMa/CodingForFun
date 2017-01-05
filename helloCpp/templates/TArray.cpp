#include "TArray.h"
#include <iostream>

/*
C++ does not allow you to declare a template in a header file and define it in a .cpp file.
The reason is that templates can only be created when the template parameters are known and
so they can't be complied in advance.

To solve this problem, you will need to declare and define template <class T> member functions in the header file

Commented codes are moved to header files.
Uncommented codes are not used, not compiled or linked.
*/

using namespace std;

/*
template <typename T>
inline TArray<T>::TArray(size_t arraySize) try : m_Size{arraySize}, m_pElements{ new T[arraySize] }
{}
catch (std::bad_alloc&)
{
	cerr << "memory allocation failed for TArray object.\n";
}

template <typename T>
inline TArray<T>::~TArray()
{
	delete[] m_pElements;
}
*/

/*
template <typename T>
inline TArray<T>::TArray(const TArray& array)
{
	m_Size = array.m_Size;
	m_pElements = new T[array.m_Size];
	for (size_t i = 0; i < m_Size; ++i)
	{
		m_pElements[i] = array.m_pElements[i];
	}
}

template <typename T>
inline TArray<T>& TArray<T>::operator=(const TArray& rhs)
{
	if (this != &rhs) // not pointing to same object
	{
		if (m_pElements) // my array is not empty
		{
			delete[] m_pElements;
		}
		m_Size = rhs.m_Size;
		m_pElements = new T[rhs.m_Size];
		for (size_t i = 0; i < m_Size; ++i)
		{
			m_pElements[i] = rhs.m_pElements[i];
		}
	}
	return *this;
}
*/

/*
template <typename T>
inline T& TArray<T>::operator[](size_t index)
{
	if (index >= m_Size)
	{
		throw std::out_of_range{ "Index too large: " + std::to_string(index) };
	}
	return m_pElements[index];
}

template <typename T>
inline const T& TArray<T>::operator[](size_t index) const
{
	if (index >= m_Size)
	{
		throw std::out_of_range{ "Index too large: " + std::to_string(index) };
	}
	return m_pElements[index];
}
*/
