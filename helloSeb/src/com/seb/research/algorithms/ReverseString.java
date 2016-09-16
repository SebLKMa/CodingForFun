package com.seb.research.algorithms;

public class ReverseString {

    public static void main(String[] args) {
        String result = "";
        String input= "hello world";
        if (args.length == 1) {
            input = args[0];
        }
        
        for (int i=input.length()-1; i>=0; i--) {
            result = result + input.charAt(i);
        }
        
        System.out.println(result);
    }

}