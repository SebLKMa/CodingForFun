/*
 * The main entry point
 *
 *  Created on: Jan 6, 2017
 *      Author: LMA
 */
#include <iostream>
#include <typeinfo> // for typeid()
#include "FileWordsCounter\FileWordsCounter.h"

int main(int argc, char* argv[])
{
	// Check the number of command line arguments
	if (argc < 2) {
		// display Usage message
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	// start processing the file
	std::cout << argv[0] << " processing " << argv[1] << "..." << std::endl;
	try
	{
		FileWordsCounter wordsCounter(argv[1]);
		wordsCounter.startProcess(20);
	}
	catch (const std::exception& ex)
	{
		std::cout << std::endl << typeid(ex).name() << ": " << ex.what() << std::endl;
	}
    return 0;
}


