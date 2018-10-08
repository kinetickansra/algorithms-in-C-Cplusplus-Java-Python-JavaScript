import java.util.Arrays;

public class CountingSort {

	public static void countingsort(int[] arr){
		int N = arr.length;
		int max = arr[0], min = arr[0];

		for (int i = 1; i < N; i++){
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		int range = max - min + 1;         //range should not be greater than 10^6 or according to available heap memory

		int[] count = new int[range];
		for (int i = 0; i < N; i++)
			count[arr[i] - min]++;

		for (int i = 1; i < range; i++)
			count[i] += count[i - 1];

		int j = 0;
		for (int i = 0; i < range; i++)
			while (j < count[i])
				arr[j++] = i + min;
		
	}

	public static void main(String[] args) {
		int[] arr = {1,9,5,2};
		countingsort(arr);
		System.out.println(Arrays.toString(arr));
	}
}
