package com.seb.Concurrency.Basics;

import static org.junit.Assert.assertEquals;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.junit.Test;

public class LockedSharedState {
	
	@Test
	public void lockedSharedState() {
		final ExecutorService executorService = Executors.newCachedThreadPool();
		
		final SimpleCounter myCounter = new SimpleCounter(); // this is a shared counter
		executorService.execute(new CounterSetter(myCounter));
		
		synchronized(myCounter) { // lock the shared counter
			myCounter.setNumber(200);
			assertEquals(200, myCounter.getNumber());
		}
	}
	
	private static class CounterSetter implements Runnable {
		private final SimpleCounter counter;
		
		private CounterSetter(SimpleCounter newCounter) {
			this.counter = newCounter;
		}

		@Override
		public void run() {
			while (true) {
				synchronized(counter) { // lock the counter
					counter.setNumber(100); // continuously set to 100
				}
			}		
		}		
	}

}
