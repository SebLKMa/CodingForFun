// the entry point for the console application.
//

#include <iostream>
#include <iomanip>
//#include <thread>
//#include <chrono>
//#include <mutex>
#include "Greet.h"
#include "tests\Test01.h"
#include "tests\Test02.h"
#include "tests\Test03.h"
#include "FileWordsCounter\FileWordsCounter.h"

using namespace std;

int main(int argc, char* argv[]) {
	Test01 test01;
	//test01.testStringTypes();
	test01.testStringUtils();
	//test01.testPtrsBasics();
	//test01.testRefsBasics();
	//test01.testLoops();
	//test01.testArraySorter();
	//test01.testQuicksort();
	//test01.testByteOrder();
	//test01.testBitShift();
	//test01.testBitMasks();
	//test01.testTArray2();
	//test01.testFileIO();
	//test01.testIsSameClass();

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();


	Test02 test02;
    /*
	test02.testInheritanceInStack();
	test02.testInheritanceInHeap();
	test02.testCpp11();
	test02.testInheritanceInHeap2();
	test02.testCpp11unique_ptr();
	test02.testCpp11unique_ptr_Move();
	test02.testCpp11shared_ptr1();
	test02.testCopy();
	test02.testAssignment();
	test02.testMove();
    */
	test02.testCopyAssign();

	//testThread();
	//testThreads();
	//testDeadlockThreads();
	//testTruckloadList();

	Test03 test03;
	//test03.testTruckloadList();
	test03.testBinaryTree();
	test03.testArrayFloorSearch();

	//FileWordsCounter wordsCounter("C:\\temp\\2489.txt");
	//wordsCounter.startCount();
	//wordsCounter.showTopBySort(20);

	cout << endl;
	cout << "Q or q key to quit...";
	char chWait;
	cin >> chWait;

	return 0;
}
