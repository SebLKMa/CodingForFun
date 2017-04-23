package com.seb.Concurrency.Basics;

/**
 * This class is not thread safe
 * @author seblkma
 *
 */
public class SimpleCounter {
	private int number = 0;
	
	public void setNumber(int newNumber) {
		this.number = newNumber;
	}
	
	public int getNumber() {
		return number;
	}

}
