import java.util.*;
public class Main {
   static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = takeInput();

	    bubblesort(arr);
	    display(arr);
	}
	public static int[] takeInput() {
	//	System.out.println("enter size of array");
		int n = scn.nextInt();
		int[] arr = new int[n];
	//	System.out.println("enetr values in array");
		for (int i = 0; i < n; i++) {
			arr[i] = scn.nextInt();
		}
		return arr;
	}

	public static void display(int[] arr)

	{
	//	System.out.println("array is:");

		for (int val : arr) {
			System.out.println(val);
		}
	}
	
	public static void bubblesort(int[] arr)
	{
	    for(int i=0;i<arr.length-1;i++)
	    {
	        for(int j=0;j<arr.length-1-i;j++)
	        {
	            if(arr[j]>arr[j+1])
	            {
	                int temp=arr[j];
	                arr[j]=arr[j+1];
	                arr[j+1]=temp;
	            }
	        }
	    }
	}
}
