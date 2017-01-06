/*
 * FileWordsCounter.h
 *
 *  Created on: Jan 6, 2017
 *      Author: LMA
 */

#ifndef FILEWORDSCOUNTER_H_
#define FILEWORDSCOUNTER_H_
#include <string>
#include <map>

using WordFrequencyPair = std::pair<unsigned int, std::string>;
using WordFrequencies = std::map<std::string, unsigned int>;

/**
 * This class reads a text file and counts the top 20 words
 */
class FileWordsCounter
{
public:
	/*
	 * Constructor
	 * @param fileName The name of input file.
	 */
	FileWordsCounter(const std::string& fileName);

	/**
	 * Starts the counting process.
	 */
	void startCount();

	void showTopBySearch(const unsigned int& max);

	void showTopBySort(const unsigned int& max);

private:
	// no copy ctor
	FileWordsCounter(const FileWordsCounter&);
	// no assignment operator
	FileWordsCounter& operator=(const FileWordsCounter&);

	void validateFile(const std::string& inFile);
	unsigned int smallest_map_value();
	unsigned int largest_map_value();

	std::string m_FileName; // holds the filename
	WordFrequencies m_WordFrequencies; // holds a map of words and their frequencies
};


#endif /* FILEWORDSCOUNTER_H_ */
