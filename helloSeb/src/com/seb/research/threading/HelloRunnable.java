package com.seb.research.threading;

public class HelloRunnable implements Runnable {

	@Override
	public void run() {
		for (int i=1; i<=3; i++) {
			System.out.println("Hello " + i);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
    public static void main(String args[]) {
        (new Thread(new HelloRunnable())).start();
    }

}
