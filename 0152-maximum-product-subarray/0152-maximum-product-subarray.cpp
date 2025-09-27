class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // int current=1;
        // int maxProduct=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     current*=nums[i];
        //     maxProduct=max(current,maxProduct);
        //     if(current<0){
        //         current=0;
        //     }
        // }
        // return maxProduct;

        int maxp=nums[0];
        int minp=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxp,minp);
            }
            maxp=max(nums[i],maxp*nums[i]);
            minp=min(nums[i],minp*nums[i]);
            result=max(result,maxp);
        }
        return result;
    }
};