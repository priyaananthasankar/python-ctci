public class Equilibrium{
 

   public int equilibrium(int arr[]){
     int sum = 0;
     for(int i =0;i<arr.length;i++){
       sum += arr[i];
     }
    
     int leftsum = 0;
     for(int i =0;i<arr.length;i++){
          sum = sum - arr[i];
          if(leftsum == sum){
            return i;
          }
          leftsum += arr[i];
     }
     return -1;
   } 

   public static void main(String args[]){
       Equilibrium obj = new Equilibrium();
       int arr[] = {-7,1,5,2,-4,3,0};
       int arr_size = arr.length;
       System.out.println(obj.equilibrium(arr));
   }
}

