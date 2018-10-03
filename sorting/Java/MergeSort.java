public class MergeSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter size: ");
		int n = s.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter elements: ");
		for (int i = 0; i < n; i++) {
		   arr[i] = s.nextInt();
		}
		int ans[] = mergesort(arr, 0, arr.length - 1);
		for (int i = 0; i < ans.length; i++) {
			System.out.println(ans[i] + " ");
		}
	}

	public static int[] mergesort(int[] arr, int low, int high) {
		if (low == high) {
			int[] base = new int[1];
			base[0] = arr[low];
			return base;
		}
		int mid = (low + high) / 2;
		int[] fhalf = mergesort(arr, low, mid);
		int[] shalf = mergesort(arr, mid + 1, high);
		int[] sorted = merge(fhalf, shalf);
		return sorted;
	}

	public static int[] merge(int[] arr1, int[] arr2) {
		int[] arr3 = new int[arr1.length + arr2.length];
		int i = 0, j = 0, k = 0;
		while (i < arr1.length && j < arr2.length) {
			if (arr1[i] > arr2[j]) {
				arr3[k] = arr2[j];
				k++;
				j++;
			} else {
				arr3[k] = arr1[i];
				k++;
				i++;

			}
		}
		while (i < arr1.length) {
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		{
			while (j < arr2.length) {
				arr3[k] = arr2[j];
				k++;
				j++;
			}
		}
		return arr3;

	}
}
