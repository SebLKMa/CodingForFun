package com.seb.research.threading;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class HelloExecutor {

	public static void main(String[] args) {
		CountDownLatch cdl1 = new CountDownLatch(5);
		CountDownLatch cdl2 = new CountDownLatch(5);
		CountDownLatch cdl3 = new CountDownLatch(5);
		CountDownLatch cdl4 = new CountDownLatch(5);
		ExecutorService es = Executors.newFixedThreadPool(2);
		
		System.out.println("Starting");
		
		// creates 4 runnable threads in threadpool with 2 threads, then execute them all
		// NOTE: only 2 runnable can run at the same time
		es.execute(new HelloRunnableWithLatch(cdl1, "A"));
		es.execute(new HelloRunnableWithLatch(cdl2, "B"));
		es.execute(new HelloRunnableWithLatch(cdl3, "C"));
		es.execute(new HelloRunnableWithLatch(cdl4, "D"));

		try {
			// current thread will wait for latches to countdown to zero
			cdl1.await();
			cdl2.await();
			cdl3.await();
			cdl4.await();
		} catch (InterruptedException ex) {
			System.out.println(ex);
		}
		
		es.shutdown(); // this must be called, otherwise program will not terminate.
		System.out.println("Stopped");
	}

}
