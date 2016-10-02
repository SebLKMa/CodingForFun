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

	public static void main(String[] args) {
		
		System.out.println("hello Seb");
	    doScanner();
	}

}
