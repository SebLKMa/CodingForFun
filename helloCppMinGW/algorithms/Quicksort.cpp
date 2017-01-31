/*
 * Quicksort.cpp
 *
 *  Created on: Jan 3, 2017
 *      Author: LMA
 */
#include <iostream>
#include <iomanip>
#include "Quicksort.h"

using namespace std;

Quicksort::Quicksort(const PWords& words)
{
	m_Words = words; // std vector assignment copies
}

Quicksort::Quicksort(const string& text, const string& separators)
{
	populateWords(text, separators);
}

Quicksort::~Quicksort()
{
	m_Words.clear();
}

Quicksort::Quicksort(const Quicksort& other)
{
	m_Words = other.m_Words; // invokes vector assigment
}

Quicksort& Quicksort::operator=(const Quicksort& other)
{
	if (this != &other) // prevent assignment to self
	{
		// MUST first de-allocate current
		m_Words.clear();

		// codes as copy ctor
		m_Words = other.m_Words; // invokes vector assigment
	}

	return *this;
}

void Quicksort::sort()
{
	if (m_Words.size() == 0)
	{
		return;
	}
	doSort(0, m_Words.size() - 1);
}

void Quicksort::showWords()
{
	const size_t fieldWidth{getIndexMaxWordLength() + 2}; // this is to align words neatly in columns
	const size_t wordsPerLine{8};

	// output the first word
	cout << std::left << std::setw(fieldWidth) << *m_Words[0];

	size_t wordsInLine{};
	for (size_t i{1}; i<m_Words.size(); ++i)
	{
		if ((*m_Words[i])[0] != (*m_Words[i - 1])[0] ||
			++wordsInLine == wordsPerLine)
		{
			wordsInLine = 0;
			cout << endl;
		}
		cout << std::setw(fieldWidth) << *m_Words[i];
	}
	cout << endl;
}

void Quicksort::doSort(size_t start, size_t end)
{
	// This is the STOP condition of the recursive function.
	// start index must be less then the end index for 2 or more elements
	if (!(start < end))
	{
		return;
	}

	// select the middle address to partition set
	swap(start, (start+end)/2);

	// since we are checking words against the selected word,
	// loop will start from non-selected word
	size_t current{start};
	for (size_t i{start + 1}; i<=end; i++)
	{
		if (*(m_Words[i]) < *(m_Words[start]))
		{
			swap(++current, i);
		}
	}
	swap(start, current);

	if (current > start) doSort(start, current);		// sort left subset if exists
	if (end > current + 1) doSort(current + 1, end);	// sort right subset if exists
}

void Quicksort::swap(size_t srcIndex, size_t destIndex)
{
	PWord temp{m_Words[srcIndex]};
	m_Words[srcIndex] = m_Words[destIndex];
	m_Words[destIndex] = temp;
}

void Quicksort::populateWords(const string& text, const string& separators)
{
	size_t start{text.find_first_not_of(separators)}; // first word
	size_t end{}; // index for end of a word

	while (start != string::npos)
	{
		end = text.find_first_of(separators, start + 1); // find end separator
		if (end == string::npos)
		{
			end = text.length();	// if end of text, set end to last+1
		}
		m_Words.push_back(std::make_shared<string>(text.substr(start, end - start)));
		start = text.find_first_not_of(separators, end + 1); // find next word
	}
}

size_t Quicksort::getIndexMaxWordLength()
{
	size_t maxLength{};
	for (auto& word : m_Words)
	{
		if (word->length() > maxLength)
		{
			maxLength = word->length();
		}
	}
	return maxLength;
}
