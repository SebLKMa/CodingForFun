package com.seb.research.threading;

import java.util.concurrent.CountDownLatch;

public class HelloRunnableWithLatch implements Runnable {
	String name;
	CountDownLatch latch;
	
	/**
	 * Automatically constructs a new thread that runs this Runnable instance.
	 * @param newLatch
	 * @param newName
	 */
	public HelloRunnableWithLatch(CountDownLatch newLatch, String newName) {
		this.latch = newLatch;
		this.name = newName;
		
		new Thread(this); // thread is created, but not run yet
	}

	@Override
	public void run() {
		for (int i=0; i<5; i++) {
			System.out.println(this.name + ": " + i);
			latch.countDown();
		}
		
	}
	
}
