import java.util.Scanner;

public class Sudoku {

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);
		int[][] arr = new int[9][9];
		int[] rows = new int[arr.length];
		int[] cols = new int[arr.length];
		int[][] sms = new int[3][3];

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				arr[i][j] = scn.nextInt();
				if (arr[i][j] > 0) {
					rows[i] = setTheBitOn(rows[i], arr[i][j]);
					cols[j] = setTheBitOn(cols[j], arr[i][j]);
					sms[i / 3][j / 3] = setTheBitOn(sms[i / 3][j / 3], arr[i][j]);
				}
			}
		}

		sudoku(arr, 1, rows, cols, sms);

	}

	private static void sudoku(int[][] arr, int cellNo, int[] rows, int[] cols, int[][] sms) {

		if (cellNo > arr.length * arr.length) {
			System.out.println("---------------------");
			
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr.length; j++) {

					System.out.print(arr[i][j] + " ");
					if ((j + 1) % 3 == 0) {
						System.out.print("|");
					}
				}
				System.out.println();
				if ((i + 1) % 3 == 0) {
					System.out.println("---------------------");
				}
			}

			System.out.println();
			System.out.println("------------------------------------");
			System.out.println();
			return;
		}

		int row = (cellNo - 1) / arr.length;
		int col = (cellNo - 1) % arr.length;

		if (arr[row][col] != 0) {
			sudoku(arr, cellNo + 1, rows, cols, sms);
		} else {
			for (int choice = 1; choice <= 9; choice++) {
				if (isNumberAvailable(arr, rows, cols, sms, choice, row, col) == true) {
					reserveANumber(arr, rows, cols, sms, choice, row, col);
					sudoku(arr, cellNo + 1, rows, cols, sms);
					releaseTheNumber(arr, rows, cols, sms, choice, row, col);
				}
			}
		}

	}

	private static boolean isBitSet(int n, int bit) {
		int mask = 1 << bit;
		if ((n & mask) > 0) {
			return true;
		} else {
			return false;
		}
	}

	private static int setTheBitOn(int num, int bit) {
		int mask = 1 << bit;
		num = num | mask;
		return num;
	}

	private static int turnTheBitOff(int num, int bit) {
		int mask = 1 << bit;
		mask = ~mask;
		num = num & mask;
		return num;
	}

	private static boolean isNumberAvailable(int[][] arr, int[] rows, int[] cols, int[][] sms, int num, int row,
			int col) {

		if (isBitSet(rows[row], num) == true) {
			return false;
		}
		if (isBitSet(cols[col], num) == true) {
			return false;
		}
		if (isBitSet(sms[row / 3][col / 3], num)) {
			return false;
		}

		return true;

	}

	private static void reserveANumber(int[][] arr, int[] rows, int[] cols, int[][] sms, int num, int row, int col) {
		arr[row][col] = num;
		rows[row] = setTheBitOn(rows[row], num);
		cols[col] = setTheBitOn(cols[col], num);
		sms[row / 3][col / 3] = setTheBitOn(sms[row / 3][col / 3], num);
	}

	private static void releaseTheNumber(int[][] arr, int[] rows, int[] cols, int[][] sms, int num, int row, int col) {
		arr[row][col] = 0;
		rows[row] = turnTheBitOff(rows[row], num);
		cols[col] = turnTheBitOff(cols[col], num);
		sms[row / 3][col / 3] = turnTheBitOff(sms[row / 3][col / 3], num);
	}
}
