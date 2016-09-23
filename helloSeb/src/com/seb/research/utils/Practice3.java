package com.seb.research.utils;

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
	

	public static void main(String[] args) {
		
		System.out.println("hello Seb");

	}

}
