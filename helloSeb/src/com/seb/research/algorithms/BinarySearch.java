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
     * Searches for the integer key in the sorted array a[].
     * @param key the search key
     * @param a the array of integers, must be sorted in ascending order
     * @return index of key in array a[] if present; -1 if not present
     */
    public static int search(int key, int[] a) {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) {
        	System.out.println("lo:" + lo + " hi:" + hi);
            // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            System.out.println("mid:" + mid);
            if      (key < a[mid]) hi = mid - 1;
            else if (key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    /**
     * Reads in a sequence of integers from the whitelist file, specified as
     * a command-line argument. Reads in integers from standard input and
     * prints to standard output those integers that do *not* appear in the file.
     */
    public static void main(String[] args) {

        // read the integers from a file
        //In in = new In(args[0]);
        int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

        // sort the array
        Arrays.sort(numbers);
        
        int myNumber = 2;
        int i = search(myNumber, numbers);
        if (i != -1){
            System.out.println("Search for " + myNumber + " found at index " + i);
        } else {
            System.out.println("Search not found: " + myNumber);
        }
    }
}