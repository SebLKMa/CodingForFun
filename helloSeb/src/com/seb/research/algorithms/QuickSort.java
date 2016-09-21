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
		//doSort(0, length - 1);
		doQuickSort(0, length - 1);
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
	
	private void doQuickSort(int left, int right) {
		int pivot = this.input[left + (right - left)/2];
		int i = left;
		int j = right;
		
		System.out.println("pivot=" + pivot + " left=" + left + " right=" + right);
		
		while (i <= j) { // move i forward and j backward not crossing each other
			while (this.input[i] < pivot) { // move i forward until we find value > pivot
				i++;
			}
			while (this.input[j] > pivot) { // move j backward until we find value < pivot
				j--;
			}
			if (i <= j) { // if i and j not crossing
				swap(i, j);
				i++;
				j--;
			}
		}
		
		if (left < j) {
			System.out.println("Left partition " + left + " to " + j);
			doQuickSort(left, j);
		}
		if (right > i) {
			System.out.println("Right partition " + i + " to " + right);
			doQuickSort(i, right);
		}
	}
	
	private void swap(int i, int j) {
		System.out.println("Swapping........" + input[i] + "," + input[j]);
		int tempData = input[i];
		input[i] = input[j];
		input[j] = tempData;
		System.out.println("After swapped..." + Arrays.toString(input));
	}
	
	
	public static void main(String[] args) {
/**
OUTPUT
======
Unsorted array: [6, 9, 3, 5, 8, 2, 7, 4]
pivot=5 left=0 right=7
Swapping........6,4
After swapped...[4, 9, 3, 5, 8, 2, 7, 6]
Swapping........9,2
After swapped...[4, 2, 3, 5, 8, 9, 7, 6]
Swapping........5,5
After swapped...[4, 2, 3, 5, 8, 9, 7, 6]
Left partition 0 to 2
pivot=2 left=0 right=2
Swapping........4,2
After swapped...[2, 4, 3, 5, 8, 9, 7, 6]
Right partition 1 to 2
pivot=4 left=1 right=2
Swapping........4,3
After swapped...[2, 3, 4, 5, 8, 9, 7, 6]
Right partition 4 to 7
pivot=9 left=4 right=7
Swapping........9,6
After swapped...[2, 3, 4, 5, 8, 6, 7, 9]
Left partition 4 to 6
pivot=6 left=4 right=6
Swapping........8,6
After swapped...[2, 3, 4, 5, 6, 8, 7, 9]
Right partition 5 to 6
pivot=8 left=5 right=6
Swapping........8,7
After swapped...[2, 3, 4, 5, 6, 7, 8, 9]
Sorted array:   [2, 3, 4, 5, 6, 7, 8, 9]
*/
		
		int[] numbers = {6, 9, 3, 5, 8, 2, 7, 4};
		System.out.println("Unsorted array: " + Arrays.toString(numbers));
		
		QuickSort sorter = new QuickSort();
		sorter.sort(numbers);
		System.out.println("Sorted array:   " + Arrays.toString(numbers));
	}

}
