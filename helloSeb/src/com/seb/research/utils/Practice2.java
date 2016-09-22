package com.seb.research.utils;

public class Practice2 {

	public static int firstFactorial(int num) { 
		int result = num;

		for (int i = num - 1; i >= 1; i--) {
	        result = result * i;
	    }
		
	    return result;
	  }
	
	public static void main(String[] args) {
		/**
		Input:4
		Output:24

		Input:8
		Output:40320 
		 */		
		System.out.println("firstFactorial 4: " + firstFactorial(4));
		System.out.println("firstFactorial 8: " + firstFactorial(8));
	}

}
