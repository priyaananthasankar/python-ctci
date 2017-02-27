public class Solution {

    public static void main(String args[]){
       Solution  s = new Solution();
       int[] nums = {1,2,3};
       return permute(nums);
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums.length == 0){
            return result;
        }
        for(int i=0;i<nums.length;i++){
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            int k = nums[i+1];
            int j = nums[i+2]; int times = 0;
            while(times <= 2){
               List<Integer> sublist = new ArrayList<Integer>();
               sublist.add(nums[i]);
               sublist.add(k);
               sublist.add(j);
               temp = k;
               k = j;
               j = temp;
               result.add(sublist);
            }
        }
        
        
        
        return result;
    }
}