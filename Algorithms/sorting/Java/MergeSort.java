import java.util.Arrays;

public class MergeSort {

	public static void main(String[] args) {
		int[] input= {12,0,5,9,44,32,12,14,5,5};
		mergeSort(input);
		for(int i:input)
			System.out.println(i);
	}
	
	public static void mergeSort(int[] input){
        if (input.length > 1) {	
            int mid = input.length/2;

            int[] leftArray = Arrays.copyOfRange(input, 0, mid);
            int[] rightArray = Arrays.copyOfRange(input,mid,input.length);

            mergeSort(leftArray);
            mergeSort(rightArray);

            merge(input,leftArray,rightArray);
        }
    }
	
	public static void merge(int[] arr, int[] arr1, int[] arr2) {
		int i=0, j=0, k=0;
		while(i<arr1.length&&j<arr2.length) {
			if(arr1[i]<=arr2[j])
				arr[k++]=arr1[i++];
			else
				arr[k++]=arr2[j++];
		}
		while(i<arr1.length)
			arr[k++]=arr1[i++];
		while(j<arr2.length)
			arr[k++]=arr2[j++];	
	}
}