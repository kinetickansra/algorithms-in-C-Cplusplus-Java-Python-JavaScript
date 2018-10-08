//Atieve Wadhwa
//Finding factorial of a number without recursion
import java.util.*;

public class factorial
{
	public static void main(String args[])
	{
		System.out.print("Enter Number: ");
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int ans = 1;
		while(n>1)
		{
			ans = n*ans;
			n = n-1;
		}

		System.out.println("The factorial is: " + ans);
		s.close();
	}
}