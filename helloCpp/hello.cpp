// helloCppConsole.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" not using pre-compiled headers
#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <string> // contains string, wstring, u16string, u32string
#include "Greet.h"
#include "HelloContainers.h"
#include "datastructures\TruckloadList.h"
#include "Box.h"
#include "tests\Test01.h"
#include "tests\Test02.h"

using namespace std;

void sayHello(int secs)
{
	cout << "Hello started" << endl;
	for (int i = 0; i<secs; ++i)
	{
		cout << i << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	cout << "Hello completed " << endl;
}

void testThread()
{
	std::thread myThread;
	myThread = std::thread(sayHello, 3);
	//myThread.join();
	myThread.detach();
}

mutex myMutex;
void threadSafeCout(int i)
{
	lock_guard<mutex> myGuard(myMutex);
	cout << " " << i << "";
}

void doForLoop(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		threadSafeCout(i);
	}
}

void testThreads()
{
	cout << endl;
	cout << "testThreads()" << endl;
	thread t1(doForLoop, 1); //  0 - 9
	thread t2(doForLoop, 2); // 10 - 19
	thread t3(doForLoop, 3); // 20 - 29
	thread t4(doForLoop, 4); // 30 - 39
	thread t5(doForLoop, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// NOTE that deadlock can also happen without locks.
	// Example:
	// thread 1 calls join on thread 2
	// thread 2 calls join on thread 1
	// Therefore, do not wait for another thread of there is a chance
	// the other thread is waiting for you.
}

mutex myMutex1, myMutex2;
void deadlockableCoutEven(int i)
{
	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	// ... do some operations here

	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);

	cout << " " << i << " ";
}

void deadlockableCoutOdd(int i)
{
	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);
	// ... do some operations here

	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	
	cout << " " << i << " ";
}

void doForLoopEvenOdd(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		if (i % 2 == 0)
		{
			deadlockableCoutEven(i);
		}
		else
		{
			deadlockableCoutOdd(i);
		}
	}
}

void testDeadlockThreads()
{
	cout << endl;
	cout << "testDeadlockThreads()" << endl;

	thread t1(doForLoopEvenOdd, 1); //  0 - 9
	thread t2(doForLoopEvenOdd, 2); // 10 - 19
	thread t3(doForLoopEvenOdd, 3); // 20 - 29
	thread t4(doForLoopEvenOdd, 4); // 30 - 39
	thread t5(doForLoopEvenOdd, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// Prevent deadlock by acquiring locks in the same order.
}

// gemerate a random integer 1 to count
inline size_t random(size_t count)
{
	return 1 + static_cast<size_t>(count * static_cast<double>(std::rand()) / RAND_MAX+1.0);
}

void testTruckloadList()
{
	const size_t dimLimit {99}; // upper limit on Box dimensions
	std::srand((unsigned)std::time(0)); // initialize random number generator

	TruckloadList list1;
	// add 12 random boxes to list
	const size_t boxCount {12};
	for (size_t i{}; i<boxCount; ++i)
	{
		list1.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}
	cout << "The first list:\n";
	list1.listBoxes();

	// Find the largest Box in the list
	shared_ptr<Box> pBox {list1.getFirstBox()};
	shared_ptr<Box> pNextBox {};
	while (pNextBox = list1.getNextBox()) // assign then test to next Box
	{
		if (pBox->compare(*pNextBox) < 0)
			pBox = pNextBox;
	}
	cout << "\nThe largest box in the first list is:";
	pBox->listBox();
	cout << endl;
	list1.deleteBox(pBox);
	cout << "\nAfter deleting the largest box, the list contains:\n";
	list1.listBoxes();

	const size_t NBOXES{20};
	vector<shared_ptr<Box>> boxes;
	for (size_t i{}; i<NBOXES; ++i)
	{
		boxes.push_back(make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}

	TruckloadList list2(boxes);
	cout << "\nThe second list:\n";
	list2.listBoxes();

	pBox = list2.getFirstBox();
	while (pNextBox = list2.getNextBox())
	{
		if (pBox->compare(*pNextBox) > 0)
		{
			pBox = pNextBox;
		}
	}

	cout << "\nThe smallest box in the first list is:";
	pBox->listBox();
	cout << endl;
}

int main() {
	//Test01 test01;
	//test01.testStringTypes();
	//test01.testPtrsBasics();
	//test01.testRefsBasics();
	//test01.testLoops();
	//test01.testArraySorter();
	//test01.testQuicksort();
	//test01.testByteOrder();
	//test01.testTArray();
	//test01.testFileIO();

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();

	Test02 test02;
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

	//testThread();
	//testThreads();
	//testDeadlockThreads();
	//testTruckloadList();

	cout << endl;
	cout << "Q or q key to quit...";
	char chWait;
	cin >> chWait;

	return 0;
}
