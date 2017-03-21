/*
 * TUtils.h
 *
 *  Created on: Mar 21, 2017
 *      Author: LMA
 */

#ifndef TUTILS_H_
#define TUTILS_H_

/**
 * This would be instantiated when T, U are of different types.
 */
template <typename T, typename U>
struct isSame
{
	static const bool VALUE = false;
};

/**
 * This would be instantiated when T, T are of the same type.
 */
template <typename T>
struct isSame<T, T>
{
	static const bool VALUE = true;
};

template <class A, class B>
bool isSameClass()
{
	return isSame<A, B>::VALUE;
}

#endif /* TUTILS_H_ */
