package com.seb.research.graphs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Queue;


/**
 * https://tutorialedge.net/breadth-first-search-with-java
 * 
 * @author likke
 *
 */
public class BreadthFirstSearch {

	public class BfsNode {
		public String name; // unique ID of node
		private BfsNode left;
		private BfsNode right;
		
		public BfsNode(String newName, BfsNode newLeft,  BfsNode newRight) {
			this.name = newName;
			this.left = newLeft;
			this.right = newRight;
		}
		
		public ArrayList<BfsNode> getChildren() {
			ArrayList<BfsNode> childNodes = new ArrayList<BfsNode>();
			if (this.left != null) childNodes.add(this.left);
			if (this.right != null) childNodes.add(this.right);
			return childNodes;
		}
		
		@Override
		public boolean equals(Object o) {
		    // self check
		    if (this == o)
		        return true;
		    // null check
		    if (o == null)
		        return false;
		    // type check and cast
		    if (getClass() != o.getClass())
		        return false;
		    BfsNode theNode = (BfsNode) o;
		    // field comparison
		    return Objects.equals(this.name, theNode.name) &&
		           Objects.equals(this.left, theNode.left) &&
		           Objects.equals(this.left, theNode.left);
		}
		
	}
	
	private BfsNode startNode;
	private BfsNode goalNode;
	
	public BreadthFirstSearch() {
	}
	
	public boolean compute(BfsNode newStart, BfsNode newGoal) {
		this.startNode = newStart;
		this.goalNode = newGoal;
		return doCompute2();
	}
	
	public boolean doCompute1() {
		if (this.startNode.equals(this.goalNode)) {
			System.out.println("Goal Node Found!");
            System.out.println(startNode);
		}
		
		Queue<BfsNode> queue = new LinkedList<>();
		ArrayList<BfsNode> explored = new ArrayList<>();
		queue.add(this.startNode);
		
		while (!queue.isEmpty()) {
			BfsNode current = queue.remove();
			if (current.equals(this.goalNode)) {
				for (BfsNode n : explored) {
					System.out.println(n.name);
				}
                return true;
			}
			else {
				if(current.getChildren().isEmpty())
                    return false;
                else
                    queue.addAll(current.getChildren());
			}
			explored.add(current);
		}

		return false;
	}
	
	public boolean doCompute2() {
		Queue<BfsNode> queue = new LinkedList<>();
		ArrayList<BfsNode> explored = new ArrayList<>();
		queue.add(this.startNode);
		
		while (!queue.isEmpty()) {
			BfsNode current = queue.remove();
			if (current.equals(this.goalNode)) {
				for (BfsNode n : explored) {
					System.out.println(n.name);
				}
                return true;
			}
			for (BfsNode n : current.getChildren()) {
				if (!explored.contains(n)) {
					explored.add(n);
					queue.add(n);
				}
			}
		}
		explored.clear();
		queue.clear();
		return false;
	}
	

	public static void testDriver() {
		BreadthFirstSearch bfs = new BreadthFirstSearch();
		BfsNode station1 = bfs.new BfsNode("Westminster", null, null);
        BfsNode station2 = bfs.new BfsNode("Waterloo", station1, null);
        BfsNode station3 = bfs.new BfsNode("Trafalgar Square", station1, station2);
        BfsNode station4 = bfs.new BfsNode("Canary Wharf", station2, station3);
        BfsNode station5 = bfs.new BfsNode("London Bridge", station4, station3);
        BfsNode station6 = bfs.new BfsNode("Tottenham Court Road", station5, station4);

        if(bfs.compute(station6, station1))
            System.out.print("Path Found!");
        else
        	System.out.print("Path NOT Found!");
	}
	
	public static void main(String[] args) {
		testDriver();

	}


}
