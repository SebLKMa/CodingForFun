package com.seb.research.utils;

import java.util.Scanner;

public class Practice3 {
	
	public class Practice3Node
	{
	    public Practice3Node[] Children;
	    public Practice3Node Right;
	}
	
	public void SetRight(Practice3Node node) {
		int j = 1;
		int max = node.Children.length;
		for (int i=0; i<max; i++) {
			node.Children[i].Right = node.Children[j];
			j++;
			SetRight(node.Children[i]);
		}
	}
	
	public static void doScanner() {
        int i = 4;
        double d = 4.0;
        String s = "HackerRank ";
        
        Scanner scan = new Scanner(System.in);
        //scanner.useDelimiter("\\n");
        try {
            //System.out.print("Enter double:\t");
            //System.out.print("Enter a string:\t");
            
            /* Declare second integer, double, and String variables. */
            int i2;
            double d2;
            String s2;

            /* Read and save an integer, double, and String to your variables.*/
            //i2 = Integer.parseInt(scan.nextLine());
            //d2 = Double.parseDouble(scan.nextLine()); 
            i2 = scan.nextInt();
            scan.nextLine();	// nextInt() does not read newline char, need to read newline explicitly
            d2 = scan.nextDouble();
            scan.nextLine(); // nextDouble() does not read newline char, need to read newline explicitly        
            s2 = scan.nextLine();

            /* Print the sum of both integer variables on a new line. */
            System.out.println(i + i2);
            /* Print the sum of the double variables on a new line. */
            System.out.printf("%.1f", d + d2);
            System.out.println();
            /* Concatenate and print the String variables on a new line; 
            	the 's' variable above should be printed first. */
            System.out.println(s + s2);
        }
        catch (Exception ex) {
        	System.err.println(ex);
        }
        finally {
        	scan.close();
        }
  	}
	
	public static void doSimpleCalc() {
        Scanner scan = new Scanner(System.in);
        double mealCost = scan.nextDouble(); // original meal price
        scan.nextLine();	// nextInt() does not read newline char, need to read newline explicitly

        int tipPercent = scan.nextInt(); // tip percentage
        scan.nextLine();	// nextInt() does not read newline char, need to read newline explicitly

        int taxPercent = scan.nextInt(); // tax percentage
        scan.nextLine();	// nextInt() does not read newline char, need to read newline explicitly

        scan.close();
      
        // Write your calculation code here.
        double totalCostGross = mealCost + 
        				(mealCost * tipPercent / 100) +
        				(mealCost * taxPercent / 100);
      
        // cast the result of the rounding operation to an int and save it as totalCost 
        int totalCost = (int) Math.round(totalCostGross);
      
        // Print your result
        System.out.println("The total meal cost is " + totalCost + " dollars.");
	}
	
	public static void doOddEven() {
	      Scanner scan = new Scanner(System.in);
	      int n = scan.nextInt(); 
	      scan.nextLine();	// nextInt() does not read newline char, need to read newline explicitly

	      scan.close();
	      String ans="";
	          
	      // if 'n' is NOT evenly divisible by 2 (i.e.: n is odd)
	      if(n%2==0){
	         ans = "Not Weird";
		  }
		  else if(n%2!=0) {
	    	 ans = "Weird";
		  }
	      System.out.println(n);
	      System.out.println(ans);
	}

	public static void main(String[] args) {
		
		System.out.println("hello Seb");
		doOddEven();
	}

}
