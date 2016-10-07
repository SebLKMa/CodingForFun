package com.seb.practice;

import java.util.Scanner;

public class Practice1 {
	
	public static void doPractice1(int n) {
		for (int i=1; i<=10; i++) {
			System.out.println(n + " x " + i + " = " +  (n*i));
		}
	}
	
	public static void doPractice1Main() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
		in.close();
		doPractice1(n);
	}
	
	public static void doPractice2(String str) {
		if (str == null || str.isEmpty()) {
			return;
		}
		
		char[] arrInput = str.toCharArray();
		int inputlen = str.length();
		int indexLen = str.length() - 1;
		int halfLen = inputlen/2;
		char[] arrEven = new char[halfLen];
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
	
	public static void doPractice2Main() {
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

	public static void main(String[] args) {
		doPractice2Main();
	}

}
