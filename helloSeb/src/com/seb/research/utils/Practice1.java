package com.seb.research.utils;

import java.util.LinkedList;
import java.util.Hashtable;
//import com.seb.research.algorithms.LinkedList;

public class Practice1 {

	public static void main(String[] args) {
		String str = "HELLO FOLLOWUP";

		//removeDupsInLinkedList1(str);
		removeDupsInLinkedList2(str);
		removeDupsInLinkedList3(str);
	}
	
	public static void removeDupsInLinkedList1(String input) {
		LinkedList<Character> nodes = new LinkedList<Character>();
		for (int i = 0; i<input.length(); i++){
			nodes.add(input.charAt(i));
		}
		int nodesSize = nodes.size() - 1;
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("Node at:" + nodes.get(0));
		System.out.println("Node at:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
		
		Hashtable<Character, Integer> table = new Hashtable<Character, Integer>();
		int i = 0;
		Object currentNode = nodes.get(i);
		while (i < nodesSize) {
			Character key = (Character)nodes.get(i);
			System.out.println("key:" + key);
			if (table.containsKey(key)) {
				nodes.remove(i);
				nodesSize--;
			} else {
				//table.put(nodes.get(i), true);
				table.put(key, i);
				i++;
			}
			//currentNode = nodes.get(i);
		}
		/*
		for (int i=1; i<nodes.size(); i++) {
			Character key = (Character)nodes.get(i);
			System.out.println("key:" + key);
			if (table.containsKey(key)) {
				nodes.remove(i);
			} else {
				//table.put(nodes.get(i), true);
				table.put(key, i);
			}
		}
		*/
		System.out.println("Table size:" + table.size());
		System.out.println("Table description:" + table.toString());
		
		nodesSize = nodes.size() - 1;
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("Node at:" + nodes.get(0));
		System.out.println("Node at:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
	}
	
	public static void removeDupsInLinkedList2(String input) {
		com.seb.research.algorithms.LinkedList nodes = new com.seb.research.algorithms.LinkedList();
		for (int i = 0; i<input.length(); i++){
			nodes.add(input.charAt(i));
		}
		int nodesSize = nodes.size();
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("First node:" + nodes.get(1));
		System.out.println("Last node:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
		
		nodes.removeDupsFast();	
		nodesSize = nodes.size();
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("First node:" + nodes.get(1));
		System.out.println("Last node:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
	}
	
	public static void removeDupsInLinkedList3(String input) {
		com.seb.research.algorithms.LinkedList nodes = new com.seb.research.algorithms.LinkedList();
		for (int i = 0; i<input.length(); i++){
			nodes.add(input.charAt(i));
		}
		int nodesSize = nodes.size();
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("First node:" + nodes.get(1));
		System.out.println("Last Node:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
		
		nodes.removeDupsSlow();
		nodesSize = nodes.size();
		System.out.println("Nodes size:" + nodesSize);
		System.out.println("First node:" + nodes.get(1));
		System.out.println("Last node:" + nodes.get(nodesSize));
		System.out.println("Nodes description:" + nodes.toString());
	}
}
