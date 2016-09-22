package com.seb.research.algorithms;

public class Palindrome {

	public static int nextPalindrome(int number, int max) {
		int from = number + 1;
		if (max < from) return 0;
		
		for (int i=from; i<max; i++) {
			if (isPalindrome(i)) {
				return i;
			}
		}
		
		return 0;
	}
	
	public static int nextSmallerPalindrome(int number) {
		int from = number - 1;
		
		for (int i=from; i>=0; i--) {
			if (isPalindrome(i)) {
				return i;
			}
		}
		
		return 0;
	}
	
	public static boolean isPalindrome(int number) {
		String stringRepresentation = String.valueOf(number);
		
	    if (isPalindrome(stringRepresentation)) {
	       return true;
	    }
	    return false;
	}
	
	public static boolean isPalindrome(String str) {
		if (str == null || str.length() == 0) return false;
		
	    if (str.equals(reverse(str)) ) {
	       return true;
	    }
	    return false;
	}
	
	public static String reverse(String str) {
		if (str == null || str.length() == 0) return str;
		
		String strReversed = null;
		int max = str.length() - 1;
		char reversed[] = new char[max + 1];
		int j = 0;
		for (int i=max; i>=0; i--) {
			reversed[j] = str.charAt(i);
			j++;
		}
		strReversed = String.copyValueOf(reversed);
		return strReversed;
	}
	
	public static void main(String[] args) {
		String input = args == null || args.length == 0 ? "ALLO" : args[0];
		System.out.println("String  : " + input);
		
		String reversedInput = reverse(input);
		System.out.println("Reversed: " + reversedInput);
		
		System.out.println(input + " isPalindrome:" + isPalindrome(input));
		
		String input2 = "ABBA";		
		System.out.println(input2 + " isPalindrome:" + isPalindrome(input2));
		
		int number1 = 1771;
		System.out.println(number1 + " nextPalindrome:" + nextPalindrome(number1, Integer.MAX_VALUE));
		System.out.println(number1 + " nextSmallerPalindrome:" + nextSmallerPalindrome(number1));

	}

}
