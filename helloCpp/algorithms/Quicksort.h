/*
 * Quicksort.h
 *
 *  Created on: Jan 3, 2017
 *      Author: LMA
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include <memory>
#include <vector>
#include <string>

using std::string;
using PWord = std::shared_ptr<string>;
using PWords = std::vector<PWord>;

class Quicksort
{
public:
	Quicksort(const PWords& words);
	Quicksort(const string& text, const string& separators);
	~Quicksort();

	// typical C++ copy ctor
	Quicksort(const Quicksort&);
	// typical C++ assignment operator
	Quicksort& operator=(const Quicksort&);

	void sort();

	void showWords();

private:
	void doSort(size_t start, size_t end);
	void swap(size_t srcIndex, size_t destIndex);
	void populateWords(const string& text, const string& separators);
	size_t getIndexMaxWordLength();

	PWords m_Words;
};

#endif /* QUICKSORT_H_ */
