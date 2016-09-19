package com.seb.research.algorithms;

/**
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 * @author
 *
 */
public class BinaryTree {
	
	/**
	 * This class is used for storage only.
	 */
	private static class Node {
		Node left;
		Node right;
		int data;
		
		Node(int newData) {
			left = null;
			right = null;
			data = newData;
		}
	}
	
	public BinaryTree() {
		root = null;
	}
	
	public boolean lookup(int data) {
		return lookup(root, data); // start searching from root
	}
	
	public void insert(int data) {
		root = insert(root, data);
	}
	
	public int size() {
		return size(root);
	}
	
	public int maxDepth() {
		return maxDepth(root);
	}
	
	public int minValue() {
		return minValue(root);
	}
	
	public int maxValue() {
		return maxValue(root);
	}
	
	public void printTree() {
		printTree(root);
	}
	
	public void printPostOrder() {
		printPostOrder(root);
	}
	
	private Node root;
	
	private boolean lookup(Node node, int data) {
		if (node == null) return false;
		
		if (data == node.data) {
			return true;
		}
		else if (data < node.data) {
			return lookup(node.left, data);
		}
		else {
			return lookup(node.right, data);
		}
	}
	
	private Node insert(Node node, int data) {
		if (node == null) {
			node = new Node(data);
		}
		else {
			if (data <= node.data) {
				node.left = insert(node.left, data);
			}
			else {
				node.right = insert(node.right, data);
			}
		}
		return node;
	}
	
	private int size(Node node) {
		if (node == null) return 0;
		
		return size(node.left) + 1 + size(node.right);
	}
	
	private int maxDepth(Node node) {
		if (node == null) return 0;
		
		int leftDepth = maxDepth(node.left);
		int rightDepth = maxDepth(node.right);
		
		// return the larger + 1
		return Math.max(leftDepth, rightDepth) + 1;
	}

	// left branch has min value
	private int minValue(Node node) {
		Node current = node;
		int value = 0;
		while (current != null) {
			value = current.data;
			current = current.left;
		}
		
		return value;
	}
	
	// right branch has max value
	private int maxValue(Node node) {
		Node current = node;
		int value = 0;
		while (current != null) {
			value = current.data;
			current = current.right;
		}
		
		return value;
	}
	
	private void printTree(Node node) {
		if (node == null) {
			return;
		}
		
		printTree(node.left);
		System.out.print(node.data + " ");
		printTree(node.right);
	}
	
	private void printPostOrder(Node node) {
		if (node == null) return;
		
		// first recur on both branches
		printPostOrder(node.left);
		printPostOrder(node.right);
		
		// then deal with the node
		System.out.print(node.data + " ");
	}
	
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.build21365();
		System.out.println("Tree has three: " + tree.lookup(3));
		System.out.println("Tree has five: " + tree.lookup(5));
		System.out.println("Tree has five: " + tree.lookup(7));
		System.out.println("Minimum value: " + tree.minValue());
		System.out.println("Maximum value: " + tree.maxValue());
		System.out.println("Tree depth: " + tree.maxDepth());
		System.out.println("Tree size: " + tree.size());
		System.out.println("Tree:");
		tree.printTree();
		System.out.println();
		System.out.println("Tree post order:");
		tree.printPostOrder();
		System.out.println();
	}
	
	public void build21365() {
		root = null;
		root = insert(root, 2);
		root = insert(root, 1);
		root = insert(root, 3);
		root = insert(root, 6);
		root = insert(root, 5);
	}

}
