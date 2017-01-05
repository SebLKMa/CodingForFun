#pragma once
#include <stddef.h> // for size_t
#include <new> // for bad_alloc
#include <iostream>


template <typename T>
class TArray
{

public:
	// ctor
	explicit TArray(size_t arraySize)
	try : m_Size{arraySize}, m_pElements{new T[arraySize]}
	{
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "memory allocation failed for TArray object.\n";
	}

	// dtor
	~TArray()
	{
		delete[] m_pElements;
	}

	//TArray(const TArray& array); // copy ctor
	inline TArray(const TArray& array)
	{
		m_Size = array.m_Size;
		m_pElements = new T[array.m_Size];
		for (size_t i = 0; i < m_Size; ++i)
		{
			m_pElements[i] = array.m_pElements[i];
		}
	}

	//TArray& operator=(const TArray& rhs); // assignment
	inline TArray<T>& operator=(const TArray& rhs)
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

	// subscript operator
	T& operator[](size_t index)
	{
		if (index >= m_Size)
		{
			throw std::out_of_range{ "Index too large: " + std::to_string(index) };
		}
		return m_pElements[index];
	}
	
	// subscript operator-const array
	const T& operator[](size_t index) const
	{
		if (index >= m_Size)
		{
			throw std::out_of_range{ "Index too large: " + std::to_string(index) };
		}
		return m_pElements[index];
	}

	size_t getSize() { return m_Size; }

private:
	T* m_pElements; // Array of type T
	size_t m_Size;   // number of array elements

};
