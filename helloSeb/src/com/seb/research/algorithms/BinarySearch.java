package com.seb.research.algorithms;

import java.util.Arrays;

/**
 *  http://algs4.cs.princeton.edu/code/
 *  The <tt>BinarySearch</tt> class provides a static method for binary
 *  searching for an integer in a sorted array of integers.
 *  <p>
 *  The <em>rank</em> operations takes logarithmic time in the worst case.
 *  <p>
 *  For additional documentation, see <a href="http://algs4.cs.princeton.edu/11model">Section 1.1</a> of
 *  <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 *
 *  @author Robert Sedgewick
 *  @author Kevin Wayne
 */
public class BinarySearch {

    /**
     * This class should not be instantiated.
     */
    private BinarySearch() { }

    /**
     * This is just simple function to sort an array of integers.
     * Warning! O(N^N)
     * @param numbers An array of unsorted integers.
     * @return An array of sorted integers in ascending order.
     */
    public static void sortAscending(int[] numbers) {
    	boolean sorted = false;
    	int temp;
    	while (true) {
    		for (int i=0; i<numbers.length-1; i++) {
    			if (numbers[i] > numbers[i+1]) {
    				temp = numbers[i];
    				numbers[i] = numbers[i+1];
    				numbers[i+1] = temp;
    				sorted = true; // indicate we did sorting
    			}
    		}
    		
    		if (!sorted) {
    			break; // fully sorted now
    		}
    		
    		sorted = false; // loop until nothing to sort
    	}
    }
    
    /**
     * Searches for the integer key in the sorted array a[].
     * @param key The search key
     * @param a The array of integers, must be sorted in ascending order
     * @return The index of key in array a[] if present; -1 if not present
     */
    public static int search(int key, int[] a) {
        int lo = 0;
        int hi = a.length - 1; // zero index
        while (lo <= hi) {
        	System.out.println("lo:" + lo + " hi:" + hi);
            // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            System.out.println("mid:" + mid);
            
            if (key < a[mid]) { 
            	hi = mid - 1; // move hi backwards
            }
            else if (key > a[mid]) {
            	lo = mid + 1; // move lo forwards
            }
            else {
            	System.out.println("Found at: " + mid);
            	return mid; // found
            }
        }
        return -1;
    }

    /**
     * Reads in a sequence of integers from the whitelist file, specified as
     * a command-line argument. Reads in integers from standard input and
     * prints to standard output those integers that do *not* appear in the file.
     */
    public static void main(String[] args) {

        // numbers array
        int[] numbers = { 3, 2, 1, 4, 7, 6, 8, 5 };

        // sort the array using Java Array
        //Arrays.sort(numbers);
        
        // sort the array using own naive sorting
        sortAscending(numbers);
        
        for (int i : numbers) {
        	System.out.print(i);
        	System.out.print(' ');
        }
        System.out.println();
        
        int myNumber = 5;
        int i = search(myNumber, numbers);
        if (i != -1){
            System.out.println("Search for " + myNumber + " found at index " + i);
        } else {
            System.out.println("Search not found: " + myNumber);
        }
    }
}