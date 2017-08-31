package com.seb.research.utils;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

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
	
	public static String dateTo(LocalDate date, int days) {
		LocalDate toDate = date.plusDays(days);
		
		DateTimeFormatter formatter = DateTimeFormatter.ISO_LOCAL_DATE;

		String formattedDate = formatter.format(toDate);
		
		return formattedDate;
	}

	public static void main(String[] args) {
		String str = "FOLLOWUP";
		System.out.println("Old string: " + str);
		String newStr = removeDupsSlow(str);
		System.out.println("New string: " + newStr);
		
		LocalDate fromDate = LocalDate.of(2017, 9, 5);
		System.out.println("Date from: " + fromDate.format(DateTimeFormatter.ISO_LOCAL_DATE));
		System.out.println("Date to  : " + dateTo(fromDate, 30));
	}
}
