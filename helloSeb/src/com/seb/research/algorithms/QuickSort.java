package com.seb.research.algorithms;

import java.util.Arrays;

/**
 * http://javarevisited.blogspot.sg/2014/08/quicksort-sorting-algorithm-in-java-in-place-example.html
 * http://javarevisited.blogspot.in/2014/08/quicksort-sorting-algorithm-in-java-in-place-example.html
 * @author LMA
 *
 */
public class QuickSort {

	private int input[];
	private int length;
	
	public void sort(int[] numbers) {
		if (numbers == null || numbers.length == 0) {
			return;
		}
		
		this.input = numbers;
		this.length = numbers.length;
		doSort(0, length - 1);
	}
	
	private void doSort(int low, int high) {
		int i = low;
		int j = high;
		
		// pivot value is middle index
		int pivotIndex = low + (high - low)/2;
		int pivotValue = input[pivotIndex];
		
		// divide in 2 arrays
		while (i <= j) {
			while (input[i] < pivotValue) {
				i++; // check value from start
			}
			while (input[j] > pivotValue) {
				j--; // check value from end
			}
			
			if (i <= j) {
				swap(i, j);
				// move index to next position on both sides
				i++;
				j--;
			}
		}
		// recurs
		if (low < j) {
			doSort(low, j);
		}
		if (i < high) {
			doSort(i, high);
		}
	}
	
	private void swap(int i, int j) {
		int tempData = input[i];
		input[i] = input[j];
		input[j] = tempData;
		System.out.println("Sorting array..." + Arrays.toString(input));
	}
	
	
	public static void main(String[] args) {
/**
OUTPUT
======
Unsorted array: [6, 5, 3, 1, 8, 7, 2, 4]
Sorting array...[1, 5, 3, 6, 8, 7, 2, 4]
Sorting array...[1, 5, 3, 6, 4, 7, 2, 8]
Sorting array...[1, 5, 3, 2, 4, 7, 6, 8]
Sorting array...[1, 2, 3, 5, 4, 7, 6, 8]
Sorting array...[1, 2, 3, 5, 4, 7, 6, 8]
Sorting array...[1, 2, 3, 4, 5, 7, 6, 8]
Sorting array...[1, 2, 3, 4, 5, 6, 7, 8]
Sorted array:   [1, 2, 3, 4, 5, 6, 7, 8]
*/
		
		int[] numbers = {6, 5, 3, 1, 8, 7, 2, 4};
		System.out.println("Unsorted array: " + Arrays.toString(numbers));
		
		QuickSort sorter = new QuickSort();
		sorter.sort(numbers);
		System.out.println("Sorted array:   " + Arrays.toString(numbers));
	}

}
