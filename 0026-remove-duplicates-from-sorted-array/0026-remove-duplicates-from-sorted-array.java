class Solution {
    public int removeDuplicates(int[] nums) {
        int k=1;
        int n=nums.length;
        if(nums.length==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[k-1]){
                nums[k]=nums[i];
                k++;
            }
           
        }
         return k;
    }
}