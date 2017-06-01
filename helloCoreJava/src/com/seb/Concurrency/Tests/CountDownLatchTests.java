package com.seb.Concurrency.Tests;

import static org.junit.Assert.*;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import org.junit.Test;

public class CountDownLatchTests {

	@Test
	public void waitComplete() throws InterruptedException {
		final ExecutorService executor = Executors.newCachedThreadPool();
		final CountDownLatch latch = new CountDownLatch(5); // start countdown from
		
		System.out.println("Parent thread: " 
				+ Thread.currentThread().getName());
		
		executor.execute(new FiniteThreadNameDisplayLatch(latch));
		latch.await(10, TimeUnit.SECONDS); // max waiting time for countdown latch
		executor.shutdownNow();
		System.out.println("Latch wait complete");
	} 

	private static class FiniteThreadNameDisplayLatch implements Runnable {
		final CountDownLatch latch;
		
		private FiniteThreadNameDisplayLatch(final CountDownLatch latch) {
			this.latch = latch;
		}
/*
		@Override
		public void run() {
			for (int i=0; i<25; i++) {
				System.out.println("Run from thread: " 
						+ Thread.currentThread().getName()
						+ ":" + i);
			}
			latch.countDown(); // decrements the countdown
		}
*/
		@Override
		public void run() {
			int count = 0;
			while (true)
			{
				count++;
				System.out.println("Counting: " + count);
				latch.countDown(); // decrements the countdown
				try {
					Thread.currentThread().sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					break;
				}
			}
		}
	}
}
