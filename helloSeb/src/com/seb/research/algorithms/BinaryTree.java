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
	
	private Node root;
	
	public BinaryTree() {
		root = null;
	}
	
	public Node getRoot() {
		return root;
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
	
	
	private boolean lookup(Node node, int data) {
		if (node == null) return false;
		
		if (data == node.data) {
			// data found in this node
			return true;
		}
		else if (data < node.data) {
			// data is less than this node, go to left node and compare
			return lookup(node.left, data);
		}
		else {
			// go to right node and compare
			return lookup(node.right, data);
		}
	}
	
	/**

       3
      / \
     2   5
    /   / \
   1   4   9
          /    insert 7 to tree
         7 
	 * 
	 * @param node
	 * @param data
	 * @return
	 */
	private Node insert(Node node, int data) {
		if (node == null) {
			// reaching here means we are at end of branch (either left or right)
			// if node is root and it is null, then tree is empty
			// we found where new node should be created
			node = new Node(data);
		}
		else {
			if (data <= node.data) {
				// data is less than this node, insert in left branch
				// when insert returns we update this node left reference
				node.left = insert(node.left, data);
			}
			else {
				// data is greater than this node, insert in right branch
				// when insert returns we update this node right reference
				node.right = insert(node.right, data);
			}
		}
		return node; // return the node as-is
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
		
		printTree(node.left); // first print left nodes
		System.out.print(node.data + " ");
		printTree(node.right); // then print right nodes
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
		//tree.build21365();
		populate(tree);
		System.out.println("Tree has three: " + tree.lookup(3));
		System.out.println("Tree has five : " + tree.lookup(5));
		System.out.println("Tree has seven: " + tree.lookup(7));
		System.out.println("Minimum value : " + tree.minValue());
		System.out.println("Maximum value : " + tree.maxValue());
		System.out.println("Tree depth    : " + tree.maxDepth());
		System.out.println("Tree size     : " + tree.size());
		System.out.println("Tree contents :");
		tree.printTree();
		System.out.println();
		System.out.println("Tree post order:");
		tree.printPostOrder();
		System.out.println();
		
		System.out.println("Root :" + tree.getRoot().data);
		
		tree.insert(4);
		System.out.println("Tree contents :");
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
/*
       2
      / \
     1   3
          \
           6
          /
         5
 */
	}
	
	public static void populate(BinaryTree tree) {
		tree.insert(3);
		tree.insert(1);
		tree.insert(2);
		tree.insert(6);
		tree.insert(5);
	/*
	       3
	      / \
	     1   6
	      \  /
	       2 5
	       
	       insert 4
	       3
	      / \
	     1   6
	      \  /
	       2 5
	        /
	       4
	 */
	}
	
}
