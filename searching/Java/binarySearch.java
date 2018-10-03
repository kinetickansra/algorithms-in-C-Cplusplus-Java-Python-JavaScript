import java.util.Scanner;
 
class BinarySearchJava
{
  public static void main(String args[])
  {
    int i, first, last, middle, n, search, array[];
 
    Scanner in = new Scanner(System.in);
    System.out.println("Enter number of elements in array");
    n = in.nextInt();
    array = new int[n];
 
    System.out.println("Enter elements in the array integers");
 
 
    for (i = 0; i < n; i++) {
      array[i] = in.nextInt();
	}
    System.out.println("Enter value to find");
    search = in.nextInt();
 
    first  = 0;
    last   = n - 1;
    middle = (first + last)/2;
 
    while( first <= last )
    {
      if ( array[middle] < search )
        first = middle + 1;    
      else if ( array[middle] == search )
      {
        System.out.println(search + " found at " + (middle + 1) + ".");
        break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      System.out.println(search + "Not in the list.\n");
  }
}