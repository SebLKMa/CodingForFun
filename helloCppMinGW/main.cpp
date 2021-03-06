//============================================================================
// Name        : HelloMingwCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tests/ClassA.h"

using namespace std;

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <mutex>
#include "tests\Test01.h"
#include "tests\Test02.h"
#include "tests\Test03.h"


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
	cout << endl;
}

void testThreads()
{
	cout << endl;
	cout << "testThreads()" << endl;

	thread t1(doForLoop, 1); //  0 - 9
	thread t2(doForLoop, 2); // 10 - 19
	//thread t3(doForLoop, 3); // 20 - 29
	//thread t4(doForLoop, 4); // 30 - 39
	//thread t5(doForLoop, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}
	cout << endl;

	t1.join();
	t2.join();
	//t3.join();
	//t4.join();
	//t5.join();

	// NOTE that deadlock can also happen without locks.
	// Example:
	// thread 1 calls join on thread 2
	// thread 2 calls join on thread 1
	// Therefore, do not wait for another thread if there is a chance
	// the other thread is waiting for you.
}

mutex myMutex1, myMutex2;
void deadlockableCoutEven(int i)
{
	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	// ... do some operations here
	cout << endl;
	cout << "Thread Id: " << std::this_thread::get_id() << endl;
	cout << "deadlockableCoutEven" << " acquired myMutex1" << endl;
	cout << "deadlockableCoutEven" << " attempt to acquire myMutex2" << endl;
	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);

	cout << "deadlockableCoutEven " << i << " ok";
}

void deadlockableCoutOdd(int i)
{
	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);
	// ... do some operations here
	cout << endl;
	cout << "Thread Id: " << std::this_thread::get_id() << endl;
	cout << "deadlockableCoutOdd" << " acquired myMutex2" << endl;
	cout << "deadlockableCoutOdd" << " attempt to acquire myMutex1" << endl;
	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);

	cout << "deadlockableCoutOdd " << i << " ok";
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
	//thread t3(doForLoopEvenOdd, 3); // 20 - 29
	//thread t4(doForLoopEvenOdd, 4); // 30 - 39
	//thread t5(doForLoopEvenOdd, 5); // 40 - 49

	//for (int i = 0; i > -50; i--)
	//{
	//	threadSafeCout(i);   // 0, -49
	//}

	t1.join();
	t2.join();
	//t3.join();
	//t4.join();
	//t5.join();

	// See Deadlock run below.
	// Prevent deadlock by acquiring locks in the same order.
}
/** Deadlocked run
testDeadlockThreads()

Thread Id: 2
deadlockableCoutEven acquired myMutex1
deadlockableCoutEven attempt to acquire myMutex2
deadlockableCoutEven 0 ok
Thread Id: 2
deadlockableCoutOdd acquired myMutex2
deadlockableCoutOdd attempt to acquire myMutex1
deadlockableCoutOdd 1 ok
Thread Id: 2
deadlockableCoutEven acquired myMutex1
deadlockableCoutEven attempt to acquire myMutex2
deadlockableCoutEven 2 ok
Thread Id: 2
deadlockableCoutOdd acquired myMutex2
deadlockableCoutOdd attempt to acquire myMutex1
deadlockableCoutOdd 3 ok
Thread Id: 2
deadlockableCoutEven acquired myMutex1
deadlockableCoutEven attempt to acquire myMutex2
deadlockableCoutEven 4 ok
Thread Id: 2
deadlockableCoutOdd acquired myMutex2
deadlockableCoutOdd attempt to acquire myMutex1

Thread Id: 3
deadlockableCoutEven acquired myMutex1
deadlockableCoutEven attempt to acquire myMutex2
 */

/* Preventing deadlock by acquiring locks in the same order
mutex1 for resA
mutex2 for resB

threadAFunc()
{
   lock(mutex1);
   lock(mutex2);
   resA.update();
   resB.update();
   unlock(mutex2);
   unlock(mutex1);
}

threadBFunc()
{
   lock(mutex2);
   resB.update();
   unlock(mutex2);

   lock(mutex1);
   lock(mutex2);
   resA.update();
   resB.update();
   unlock(mutex2);
   unlock(mutex1);
}
*/

int main(int argc, char* argv[]) {
	A::doSimpleTest();

	//Test01 test01;
	//test01.testStringTypes();
	//test01.testStringUtils();
	//test01.testPtrsBasics();
	//test01.testRefsBasics();
	//test01.testLoopsForBinaryGaps();
	//test01.testArraySorter();
	//test01.testQuicksort();
	//test01.testByteOrder();
	//test01.testBitShift();
	//test01.testBitMasks();
	//test01.testTArray2();
	//test01.testFileIO();

	//Test02 test02;
	//test02.testInheritanceInStack();
	//test02.testInheritanceInHeap();
	//test02.testCpp11();
	//test02.testInheritanceInHeap2();
	//test02.testCpp11unique_ptr();
	//test02.testCpp11unique_ptr_Move();
	//test02.testCpp11shared_ptr1();
	//test02.testCopy();
	//test02.testAssignment();
	//test02.testMove();
	//test02.testCopyAssign();

	Test03 test03;
	test03.testTruckloadList();

	//testThread();
	//testThreads();
	//testDeadlockThreads();

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();

	//FileWordsCounter wordsCounter("C:\\temp\\2489.txt");
	//wordsCounter.startCount();
	//wordsCounter.showTopBySort(20);

	cout << endl;
	cout << "Q or q key to quit...";
	char chWait;
	cin >> chWait;

	return 0;
}

