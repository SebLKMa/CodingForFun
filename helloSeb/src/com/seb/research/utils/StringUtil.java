package com.seb.research.utils;

public class StringUtil {

	public static String removeDupsSlow(String str) {
		if (str == null || str.isEmpty()) return "";
		
		char[] chrs = str.toCharArray();
		int len = str.length();
		int tail = 1; // point the tail to second character
		for (int currentIndex=1; currentIndex < len; currentIndex++) {
			int runnerIndex; // runner always starts from beginning
			for (runnerIndex = 0; runnerIndex < tail; runnerIndex++) {
				if (chrs[runnerIndex] == chrs[currentIndex]) {
					break;
				}
			}
			if (runnerIndex == tail) {
				chrs[tail] = chrs[currentIndex];
				tail++;
			}
			
		}
		chrs[tail] = 0;
		char[] newChrs = new char[tail];
		for (int i=0; i<tail; i++) {
			newChrs[i] = chrs[i];
		}
		String newStr = new String(newChrs);
		return newStr;
	}

	public static void main(String[] args) {
		String str = "FOLLOWUP";
		System.out.println("Old string: " + str);
		String newStr = removeDupsSlow(str);
		System.out.println("New string: " + newStr);
	}
}
