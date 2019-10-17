import java.util.Scanner;
class BubbleSort{
  public static void main(String args[]){
    //Scanning the elements of the array
    Scanner sc=new Scanner(System.in);
    System.out.println("enter no. of elements");
    int n=sc.nextInt();
    int[] a=new int[n];
    for(int i=0;i<n;i++) a[i]=sc.nextInt();
    //Sorting
    for (int c = 0; c < ( n - 1 ); c++) {
      for (int d = 0; d < n - c - 1; d++) {
        if (a[d] >a[d+1])
        {
          int swap= a[d];
          a[d]   = a[d+1];
          a[d+1] = swap;
        }
      }
    }
    for(int j=0;j<a.length;j++)
        System.out.print(a[j]+" ");
    System.out.println();
 
        
  }
}
