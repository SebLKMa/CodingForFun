package com.seb.research.algorithms;

import java.util.Arrays;

public class MergeArrays {
	
	public static void merge(int[] input1, int[] input2, int[] output) throws Exception {
		int i, j, k, input1Length, input2Length;
		i = 0;
		j = 0;
		k = 0;
		input1Length = input1.length;
		input2Length = input2.length;
		
		if (output.length < (input1Length + input2Length)) {
			throw new Exception("Output length must be greater or equals to sum of input1 and input2.");
		}
		
		while (i < input1Length && j < input2Length) {
			if (input1[i] < input2[j]) {
				output[k] = input1[i];
				i++;
			}
			else {
				output[k] = input2[j];
				j++;
			}
			k++;
		}
		// appending any remaining from input1 or input2 
		if (i < input1Length) {
			for (int p = i; p < input1Length; p++) {
				output[k] = input1[p];
				k++;
			}
		}
		else {
			for (int p = j; p < input2Length; p++) {
				output[k] = input2[p];
				k++;
			}
		}
	}

	public static void main(String[] args) {
		int input1[] = {1, 3, 4, 6, 2};
		int input2[] = {3, 5, 7};
		int output[] = new int[8];
		
		try {
			System.out.println("Input1 array: " + Arrays.toString(input1));
			System.out.println("Input2 array: " + Arrays.toString(input2));
			merge(input1, input2, output);
			System.out.println("Merged array: " + Arrays.toString(output));
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
