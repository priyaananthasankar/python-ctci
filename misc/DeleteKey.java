/** Delete all occurrences of a key in an array
    and shift the array */
public class DeleteKey {

  public static void main(String args[]){
     int a[] = {5,3,7,11,2,3,13,5,7};
     int k = 3;
     int j = 0;int i=0;
     int n = a.length;
     while (j < a.length){
       if(a[j] != k){
         a[i] = a[j];
         i++;
       }
       j++;
     }
     for(int p =0; p<i;p++){
     System.out.print(a[p] + " ");
    }
  }

}
