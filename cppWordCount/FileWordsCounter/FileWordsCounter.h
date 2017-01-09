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

// alias typedefs
using WordFrequencyPair = std::pair<unsigned int, std::string>;
using WordFrequencies = std::map<std::string, unsigned int>;

/**
 * This class reads a text file and counts the top N words.
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
	 * @param maxWords The top number of words to show after processing
	 */
	void startProcess(const unsigned int& topNwords);

private:
	// no copy ctor
	FileWordsCounter(const FileWordsCounter&);
	// no assignment operator
	FileWordsCounter& operator=(const FileWordsCounter&);

	// validate the input file
	void validateFile();

	// populate the word frequency counts
	void populateWordFrequencies();

	// display the top N max frequency
	void showTop(const unsigned int& max);

	std::string m_FileName; // holds the filename
	WordFrequencies m_WordFrequencies; // holds a map of words and their frequencies
};


#endif /* FILEWORDSCOUNTER_H_ */
