package lecture2;

import java.util.Scanner;

public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, search, array[];
		 
	    Scanner in = new Scanner(System.in);
	    System.out.println("Enter number of elements");
	    n = in.nextInt();
	    array = new int[n];
	 
	    System.out.println("Enter the elements in ascending order");
	 
	    for (int i = 0; i < n; i++)
	      array[i] = in.nextInt();
	 
	    System.out.println("Enter element to be searched");
	    search = in.nextInt();
	
	    int low = 0, high = n - 1;
	    while(low <= high) {
	    	int mid = (low + high)/2;
	    	if(array[mid] > search) {
	    		high = mid - 1;
	    	}else if(array[mid] < search) {
	    		low = mid + 1;
	    	}else {
	    		System.out.println("Element found at index " + mid);
	    		return;
	    	}
	    }
	    
	    System.out.println("Element not present");
	}
}
