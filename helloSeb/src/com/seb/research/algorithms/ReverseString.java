package com.seb.research.algorithms;

public class ReverseString {

    public static void main(String[] args) {
        String result = "";
        String input= "dlrow olleh";
        if (args.length == 1) {
            input = args[0];
        }
        
        //result = reverse(input);
        result = reverseSmart(input);
        
        System.out.println(result);
    }

    public static String reverse(String input) {
        String result = "";
        
        for (int i=input.length()-1; i>=0; i--) {
            result = result + input.charAt(i);
        }
        return result;
    }
    
    public static String reverseSmart(String input) {
        String result = "";
        if (input.isEmpty()) return result;
        
        char[] inputArray = input.toCharArray();
        
        int len = inputArray.length;
        int mid = (len)/2;
        char temp;
        for (int i=0; i<mid; i++) {
        	// swap inputArray[i] with inputArray[len-i-1]
    		temp = inputArray[i];
    		inputArray[i] = inputArray[len-i-1];
    		inputArray[len-i-1] = temp;
        }
        result = String.valueOf(inputArray);
        return result;
    }
}