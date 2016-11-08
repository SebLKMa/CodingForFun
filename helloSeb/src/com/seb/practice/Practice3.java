package com.seb.practice;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Set;

public class Practice3 {

	public static String readFile(String file) throws IOException {
	    BufferedReader reader = new BufferedReader(new FileReader (file));
	    String         line = null;
	    //StringBuilder  stringBuilder = new StringBuilder();
	    String         ls = System.getProperty("\\n");
	    
	    FileWriter fw = new FileWriter(file+"2"+".txt", true);
	    BufferedWriter bw = new BufferedWriter(fw);
	    PrintWriter out = new PrintWriter(bw);

	    Hashtable table = new Hashtable();
	    
	    try {
	    	int beginIndex = 0;
	    	String strSearch = ", key ";
	    	String strWrite = "";
	        while((line = reader.readLine()) != null) {
	            if (line.indexOf("authenticating user") != -1) {
	        
	            	beginIndex = line.indexOf(strSearch);
	            	if (beginIndex != -1) {
	            		beginIndex += strSearch.length();
	            		strWrite = line.substring(beginIndex);
	            		if (!table.containsKey(strWrite)) {
	            			table.put(strWrite, strWrite);
	            		}
	            	    //out.println(line.substring(beginIndex));

	            	}
	            }
	            //stringBuilder.append(line);
	            //stringBuilder.append(ls);
	        }
	        //return stringBuilder.toString();
	        
	        Set<String> keys = table.keySet();
	        
	        //Obtaining iterator over set entries
	        Iterator<String> itr = keys.iterator();
	     
	        //Displaying Key and value pairs
	        while (itr.hasNext()) { 
	           // Getting Key
	        	strWrite = itr.next();

	           /* public V get(Object key): Returns the value to which 
	            * the specified key is mapped, or null if this map 
	            * contains no mapping for the key.
	            */
	           //System.out.println("Key: "+str+" & Value: "+hashtable.get(str));
	        	out.println(strWrite);
	        } 
	        
	    } finally {
	        reader.close();
	        bw.close();
	        out.close();
	        table.clear();
	    }
	    return "";
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			String strRead = readFile("C:\\Docs\\SDP R1\\DEFECTS\\output\\output.txt");
			System.out.println(strRead);
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
