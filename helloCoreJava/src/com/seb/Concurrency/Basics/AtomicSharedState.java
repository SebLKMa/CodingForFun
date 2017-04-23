package com.seb.Concurrency.Basics;

import static org.junit.Assert.assertEquals;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.junit.Test;

public class AtomicSharedState {

	@Test
	public void atomicSharedState() {
		final ExecutorService executorService = Executors.newCachedThreadPool();
		
		final AtomicCounter myCounter = new AtomicCounter(); // this is a threadsafe counter
		executorService.execute(new CounterSetter(myCounter));
		
		// no need to lock the atomic counter
		final int value = myCounter.getNumber().incrementAndGet();
		assertEquals(1, value);
	}
	
	private static class CounterSetter implements Runnable {
		private final AtomicCounter counter;
		
		private CounterSetter(AtomicCounter newCounter) {
			this.counter = newCounter;
		}

		@Override
		public void run() {
			while (true) {
				// no need lock the counter
				// continuously set to 0
				counter.getNumber().set(0);
			}		
		}		
	}
}
