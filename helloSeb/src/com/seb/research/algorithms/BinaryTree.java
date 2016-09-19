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

	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.build213();
		System.out.println("Tree has three: " + tree.lookup(3));
		System.out.println("Tree has five: " + tree.lookup(5));
	}
	
	public void build213() {
		root = null;
		root = insert(root, 2);
		root = insert(root, 1);
		root = insert(root, 3);
	}

}
