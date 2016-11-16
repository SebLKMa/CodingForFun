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
public class Search {

	public class GraphNode {
		public String name; // unique ID of node
		private GraphNode left;
		private GraphNode right;
		
		public GraphNode(String newName, GraphNode newLeft,  GraphNode newRight) {
			this.name = newName;
			this.left = newLeft;
			this.right = newRight;
		}
		
		public ArrayList<GraphNode> getChildren() {
			ArrayList<GraphNode> childNodes = new ArrayList<GraphNode>();
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
		    GraphNode theNode = (GraphNode) o;
		    // field comparison
		    return Objects.equals(this.name, theNode.name) &&
		           Objects.equals(this.left, theNode.left) &&
		           Objects.equals(this.left, theNode.left);
		}
		
	}
	
	public class DfsGraphNode extends GraphNode {
		public boolean visited = false;
		public DfsGraphNode(String newName, GraphNode newLeft,  GraphNode newRight) {
			super(newName, newLeft, newRight);
		}
	}
	
	private GraphNode startNode;
	private GraphNode goalNode;
	
	public Search() {
	}
	
	// TODO: make compute abstract or use template pattern
	public boolean computeBFS(GraphNode newStart, GraphNode newGoal) {
		System.out.println("computeBFS");
		this.startNode = newStart;
		this.goalNode = newGoal;
		
		if (this.startNode.equals(this.goalNode)) {
			System.out.println("Goal Node Found!");
            System.out.println(startNode);
            return true;
		}
		
		return doBreadthFirstSearch2();
	}
	
	// TODO: make compute abstract or use template pattern
	public boolean computeDFS(GraphNode newStart, GraphNode newGoal) {
		System.out.println("computeDFS");
		this.startNode = newStart;
		this.goalNode = newGoal;
		
		if (this.startNode.equals(this.goalNode)) {
			System.out.println("Goal Node Found!");
            System.out.println(startNode);
            return true;
		}
		ArrayList<GraphNode> visited = new ArrayList<>();
		return doDepthFirstSearch(this.startNode, visited);
	}
	
	public boolean doBreadthFirstSearch1() {
		Queue<GraphNode> queue = new LinkedList<>();
		ArrayList<GraphNode> explored = new ArrayList<>();
		queue.add(this.startNode);
		
		while (!queue.isEmpty()) {
			GraphNode current = queue.remove();
			if (current.equals(this.goalNode)) {
				for (GraphNode n : explored) {
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
	
	public boolean doBreadthFirstSearch2() {
		Queue<GraphNode> queue = new LinkedList<>();
		ArrayList<GraphNode> visited = new ArrayList<>();
		queue.add(this.startNode);
		
		while (!queue.isEmpty()) {
			GraphNode current = queue.remove();
			if (current.equals(this.goalNode)) {
				for (GraphNode n : visited) {
					System.out.println(n.name);
				}
                return true;
			}
			for (GraphNode n : current.getChildren()) {
				if (!visited.contains(n)) {
					visited.add(n);
					queue.add(n);
				}
			}
		}
		visited.clear();
		queue.clear();
		return false;
	}
	
	//ArrayList<GraphNode> visited = new ArrayList<>();
	public boolean doDepthFirstSearch(GraphNode node, ArrayList<GraphNode> visited) {
		System.out.println(node.name);
		
		if (node.equals(this.goalNode)) {
            return true;
		}
		
		visited.add(node);
		
		for (GraphNode current : node.getChildren()) {
			if (!visited.contains(current)) {
				if (doDepthFirstSearch(current, visited)) {
					return true;
				}
			}
		}
		return false;
	}

	public static void testDriver() {
		Search bfs = new Search();
		GraphNode station1 = bfs.new GraphNode("Westminster", null, null);
        GraphNode station2 = bfs.new GraphNode("Waterloo", station1, null);
        GraphNode station3 = bfs.new GraphNode("Trafalgar Square", station1, station2);
        GraphNode station4 = bfs.new GraphNode("Canary Wharf", station2, station3);
        GraphNode station5 = bfs.new GraphNode("London Bridge", station4, station3);
        GraphNode station6 = bfs.new GraphNode("Tottenham Court Road", station5, station4);

        if(bfs.computeBFS(station6, station1))
            System.out.println("BFS Path Found!");
        else
        	System.out.println("BFS Path NOT Found!");
        
        Search dfs = new Search();
        if(bfs.computeDFS(station6, station1))
            System.out.println("DFS Path Found!");
        else
        	System.out.println("DFS Path NOT Found!");
	}
	
	public static void main(String[] args) {
		testDriver();

	}


}
