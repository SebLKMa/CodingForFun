package com.seb.Concurrency.Basics;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * This class is thread safe.
 * The counter uses AtomicInteger.
 * There are other Atomic class, e.g AtomicBoolean, AtomicReference etc.
 * @author seblkma
 *
 */
public class AtomicCounter {
	private final AtomicInteger number = new AtomicInteger(); // points to
	
	// Not needed, use methods from AtomicInteger instead
	//public void setNumber(int newNumber) {
	//	this.number = newNumber;
	//}
	
	public AtomicInteger getNumber() {
		return number;
	}
}
