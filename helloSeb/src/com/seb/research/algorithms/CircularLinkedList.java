package com.seb.research.algorithms;

import java.util.Scanner;

class LinkedListNode
{
    protected int data;
    protected LinkedListNode link;
 
    /*  Constructor  */
    public LinkedListNode()
    {
        link = null;
        data = 0;
    }    
    /*  Constructor  */
    public LinkedListNode(int d,LinkedListNode n)
    {
        data = d;
        link = n;
    }    
    /*  Function to set link to next Node  */
    public void setLink(LinkedListNode n)
    {
        link = n;
    }    
    /*  Function to set data to current Node  */
    public void setData(int d)
    {
        data = d;
    }    
    /*  Function to get link to next node  */
    public LinkedListNode getNext()
    {
        return link;
    }    
    /*  Function to get data from current Node  */
    public int getData()
    {
        return data;
    }
}
 
class CircularLinkedList
{
    protected LinkedListNode start ;
    protected LinkedListNode end ;
    public int size ;
 
    /* Constructor */
    public CircularLinkedList()
    {
        start = null;
        end = null;
        size = 0;
    }
    /* Function to check if list is empty */
    public boolean isEmpty()
    {
        return start == null;
    }
    /* Function to get size of the list */
    public int getSize()
    {
        return size;
    }
    /* Function to insert element at the begining */
    public void insertAtStart(int val)
    {
        LinkedListNode nptr = new LinkedListNode(val,null);    
        nptr.setLink(start);
        if(start == null)
        {            
            start = nptr;
            nptr.setLink(start);
            end = start;            
        }
        else
        {
            end.setLink(nptr);
            start = nptr;        
        }
        size++ ;
    }
    /* Function to insert element at end */
    public void insertAtEnd(int val)
    {
        LinkedListNode nptr = new LinkedListNode(val,null);    
        nptr.setLink(start);
        if(start == null)
        {            
            start = nptr;
            nptr.setLink(start);
            end = start;            
        }
        else
        {
            end.setLink(nptr);
            end = nptr;            
        }
        size++ ;
    }
    /* Function to insert element at position */
    public void insertAtPos(int val , int pos) 
    {
        LinkedListNode nptr = new LinkedListNode(val,null);                
        LinkedListNode ptr = start;
        pos = pos - 1 ;
        for (int i = 1; i < size - 1; i++) 
        {
            if (i == pos) 
            {
                LinkedListNode tmp = ptr.getNext() ;
                ptr.setLink( nptr );
                nptr.setLink(tmp);
                break;
            }
            ptr = ptr.getNext();
        }
        size++ ;
    }
    /* Function to delete element at position */
    public void deleteAtPos(int pos)
    {    
        if (size == 1 && pos == 1)
        {
            start = null;
            end = null;
            size = 0;
            return ;
        }        
        if (pos == 1) 
        {
            start = start.getNext();
            end.setLink(start);
            size--; 
            return ;
        }
        if (pos == size) 
        {
            LinkedListNode s = start;
            LinkedListNode t = start;
            while (s != end)
            {
                t = s;
                s = s.getNext();
            }
            end = t;
            end.setLink(start);
            size --;
            return;
        }
        LinkedListNode ptr = start;
        pos = pos - 1 ;
        for (int i = 1; i < size - 1; i++) 
        {
            if (i == pos) 
            {
                LinkedListNode tmp = ptr.getNext();
                tmp = tmp.getNext();
                ptr.setLink(tmp);
                break;
            }
            ptr = ptr.getNext();
        }
        size-- ;
    }
    /* Function to display contents */
    public void display()
    {
        System.out.print("\nCircular Singly Linked List = ");
        LinkedListNode ptr = start;
        if (size == 0) 
        {
            System.out.print("empty\n");
            return;
        }
        if (start.getNext() == start) 
        {
            System.out.print(start.getData()+ "->"+ptr.getData()+ "\n");
            return;
        }
        System.out.print(start.getData()+ "->");
        ptr = start.getNext();
        while (ptr.getNext() != start) 
        {
            System.out.print(ptr.getData()+ "->");
            ptr = ptr.getNext();
        }
        System.out.print(ptr.getData()+ "->");
        ptr = ptr.getNext();
        System.out.print(ptr.getData()+ "\n");
    }
    
    public LinkedListNode findBeginning(LinkedListNode assumedHead) {
    	LinkedListNode n1 = assumedHead;
    	LinkedListNode n2 = assumedHead;
    	
    	// find meeting point
    	while (n2.getNext() != null) {
    		n1 = n1.getNext();
    		n2 = n2.getNext().getNext();
    		if (n1 == n2) {
    			// both pointing to same node
    			break;
    		}
    	}
    	
    	// sanity check - there is no meeting point, therefore no loop
    	if (n2.getNext() == null) {
    		return null;
    	}
    	
    	/** Move n1 back to Head. Keep n2 at Meeting Point. Each a K steps
    	 *  from the Loop Start. If they move at the same pace, they must
    	 *  meet at Loop Start.
    	 */
    	n1 = assumedHead;
    	while (n1 != n2) {
    		n1 = n1.getNext();
    		n2 = n2.getNext();
    	}
    	// now n2 points to the start of the loop
    	return n2;
    }
    
    public static void main(String[] args)
    {            
        Scanner scan = new Scanner(System.in);
        try
        { 
	        /* Creating object of linkedList */
	        CircularLinkedList list = new CircularLinkedList(); 
	        System.out.println("Circular Singly Linked List Test\n");          
	        char ch;
	        /*  Perform list operations  */
	        do
	        {
	            System.out.println("\nCircular Singly Linked List Operations\n");
	            System.out.println("1. insert at begining");
	            System.out.println("2. insert at end");
	            System.out.println("3. insert at position");
	            System.out.println("4. delete at position");
	            System.out.println("5. check empty");
	            System.out.println("6. get size");            
	            int choice = scan.nextInt();            
	            switch (choice)
	            {
	            case 1 : 
	                System.out.println("Enter integer element to insert");
	                list.insertAtStart( scan.nextInt() );                     
	                break;                          
	            case 2 : 
	                System.out.println("Enter integer element to insert");
	                list.insertAtEnd( scan.nextInt() );                     
	                break;                         
	            case 3 : 
	                System.out.println("Enter integer element to insert");
	                int num = scan.nextInt() ;
	                System.out.println("Enter position");
	                int pos = scan.nextInt() ;
	                if (pos <= 1 || pos > list.getSize() )
	                    System.out.println("Invalid position\n");
	                else
	                    list.insertAtPos(num, pos);
	                break;                                          
	            case 4 : 
	                System.out.println("Enter position");
	                int p = scan.nextInt() ;
	                if (p < 1 || p > list.getSize() )
	                    System.out.println("Invalid position\n");
	                else
	                    list.deleteAtPos(p);
	                break;
	            case 5 : 
	                System.out.println("Empty status = "+ list.isEmpty());
	                break;                   
	            case 6 : 
	                System.out.println("Size = "+ list.getSize() +" \n");
	                break;                         
	             default : 
	                System.out.println("Wrong Entry \n ");
	                break;   
	            }
	            /*  Display List  */ 
	            list.display();
	            System.out.println("\nDo you want to continue (Type y or n) \n");
	            ch = scan.next().charAt(0);            
	        } while (ch == 'Y'|| ch == 'y');
        }
        finally
        {
        	scan.close();
        }
        
    } 
}
 

