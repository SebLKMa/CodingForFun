package com.seb.Concurrency.Tests;

import static org.junit.Assert.*;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Executor;

import org.junit.Test;

public class ExecutorSameThread {

	@Test
	public void sameThread() {
		final Executor executor = new Executor() {

			@Override
			public void execute(Runnable command) {
				command.run();
				
			}
			
		};
		
		System.out.println("Main thread: " + Thread.currentThread().getName());
		executor.execute(new FiniteThreadNameDisplay());
		System.out.println("Main thread: " + Thread.currentThread().getName() + " completed");
	}

	private static class FiniteThreadNameDisplay implements Runnable {
		@Override
		public void run() {
			for (int i=0; i<25; i++) {
				System.out.println("Run from thread: " 
						+ Thread.currentThread().getName()
						+ ":" + i);
			}
		}		
	}
}
