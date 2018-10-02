public class quicksort{
    public static void main(String[] args){
        int [] arr={5,4,1,2,7,6,8};
        quicksort(arr,0,6);
        for (int i=0;i<7 ;i++ ) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    static void quicksort(int[] arr,int l,int h){
        if (l<h){
            int x=partition(arr,l,h);
            quicksort(arr,l,x-1);
            quicksort(arr,x+1,h);
        }
    }
    static int partition(int[] arr,int l,int h){
        int pivot=arr[h];
        int i=l-1;
        for (int j=l;j<h;j++){
            if (arr[j]<=pivot){
                i+=1;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        i+=1;
        arr[h]=arr[i];
        arr[i]=pivot;
        return i;
    }
}

