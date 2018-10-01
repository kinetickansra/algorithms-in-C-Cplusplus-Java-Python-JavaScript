import java.util.*;
public class Main {
   	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = takeInput();

		 int item = scn.nextInt();
    
	    System.out.println(binarySearch(arr,item));
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
	public static int binarySearch(int[] arr, int item) {
		int lo = 0;
		int hi = arr.length - 1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (item > arr[mid]) {
				lo = mid + 1;
			} else if (item < arr[mid]) {
				hi = mid - 1;
			} else {
				return mid;
			}
		}

		return -1;
	}

}
