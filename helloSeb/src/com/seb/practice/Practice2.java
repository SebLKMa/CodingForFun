package com.seb.practice;

import java.util.Scanner;

public class Practice2 {
	
	public static String doReverse(String str) {
		if (str == null || str.isEmpty()) {
			return str;
		}
		
		char[] arrInput = str.toCharArray();
		char[] arrOutput = str.toCharArray();
		int len = arrInput.length - 1;
		
		int j = 0;
		for (int i=len; i>=0; i--) {
			arrOutput[j] = arrInput[i];
			j++;
		}
		
		String strNew = new String(arrOutput);
		return strNew;
	}

	public static void doPractice2(String str) {
		if (str == null || str.isEmpty()) {
			return;
		}
		
		char[] arrInput = str.toCharArray();
		int inputlen = str.length();
		int indexLen = str.length() - 1;
		int halfLen = inputlen/2;
		char[] arrEven = new char[halfLen+1];
		char[] arrOdd = new char[halfLen];
		
		int j = 0;
		int k = 0;
		for (int i=0; i<=indexLen; i++) {
			if (i == 0 || i%2==0) { // even index
				arrEven[j] = arrInput[i];
				j++;
			}
			else { // odd index
				arrOdd[k] = arrInput[i];
				k++;
			}
		}
		
		String newStr = new String(arrEven) + " " + new String(arrOdd);
		System.out.println(newStr);
	}
	
	public static void doPractice2a() {
        Scanner in = new Scanner(System.in);
        try {
            int n = in.nextInt();
            in.nextLine();
            if (n <= 0 || n >= 10) {
            	return;
            }
            
            String[] arrStr = new String[n];
            for (int i=0; i<n; i++) {
            	arrStr[i] = in.nextLine();
            }
            
            for (int i=0; i<n; i++) {
            	doPractice2(arrStr[i]);
            }
        }
        finally {
        	in.close();
        }

	}

	public static void doPractice2b() {
        Scanner in = new Scanner(System.in);
        try {
            int n = in.nextInt();
            in.nextLine();
            if (n <= 0 || n >= 10) {
            	return;
            }
            
            String[] arrStr = new String[n];
            for (int i=0; i<n; i++) {
            	arrStr[i] = in.nextLine();
            }
            
            for (int i=0; i<n; i++) {
            	String str = doReverse(arrStr[i]);
            	System.out.println(str);
            }
        }
        finally {
        	in.close();
        }

	}
	
	public static int doFactorial(int n) {
		if (n <= 1) {
			return n;
		}
		int n1 = n - 1;
		return n * doFactorial(n1);
	}
	
	public static void doPractice2c() {
        Scanner in = new Scanner(System.in);
        try {
            int n = in.nextInt();
            in.nextLine();
            if (n <= 0 || n >= 12) {
            	return;
            }
            
    		int factorial = doFactorial(n);
    		System.out.println("factorial of " + n + " = " + factorial);
        }
        finally {
        	in.close();
        }
		

	}
	
	public static void main(String[] args) {
		doPractice2c();
		
	}

}
