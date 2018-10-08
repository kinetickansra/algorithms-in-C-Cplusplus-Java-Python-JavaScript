import java.util.*;
import java.lang.*;
import java.io.*;

class HeapSort {

	public static void main(String[] args) throws java.lang.Exception {
		HeapSort hs = new HeapSort();
		int[] arr=new int[] {1,3,2,0};
		hs.HeapSort(arr);
		System.out.println(Arrays.toString(arr));  //this line print sorted array in string format
	}
	private int heapsize;
	public void HeapSort(int[] arr) {
		buildHeap(arr);
		for(int i=arr.length;i>1;i--) {
			int temp = arr[0];      //swaping
			arr[0] = arr[i-1];
			arr[i-1] = temp;
			
			heapsize--;
			heapify(arr, 1);
		}
	}
	private void buildHeap(int[] a) {
		heapsize = a.length;
		for (int i = heapsize / 2; i > 0; i--) {
			heapify(a, i);
		}
	}

	private void heapify(int[] a, int i) {
		int l = left(i);
		int r = right(i);
		int largest;//System.out.println(heapSize()+" "+l+" "+r+" "+i);
		if (l <= heapSize() && a[l - 1] > a[i - 1]) {
			largest = l;
		} else {
			largest = i;
		}
		if (r <= heapSize() && a[r - 1] > a[largest - 1]) {
			largest = r;
		}
		if (largest != i) {
			// exchange a[i], a[largest]
			int tmp = a[i - 1];
			a[i - 1] = a[largest - 1];
			a[largest - 1] = tmp;
			heapify(a, largest);
		}
	}

	public int heapSize() {
		return heapsize;
	}

	public int parent(int i) {
		return (i / 2);
	}

	public int left(int i) {
		return (2 * i);
	}

	public int right(int i) {
		return (2 * i + 1);
	}
}
