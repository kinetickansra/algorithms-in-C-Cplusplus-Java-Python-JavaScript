import java.util.*;
public class Main {
   static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = takeInput();

	    insertionsort(arr);
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
    
    public static void insertionsort(int[] arr) {
		int n = arr.length;
		for (int i = 1; i < n; i++) {
			int temp = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > temp) // shifting
			{
				arr[j + 1] = arr[j];
				j--;
			}

			arr[j + 1] = temp;
		}
	}

}
	
