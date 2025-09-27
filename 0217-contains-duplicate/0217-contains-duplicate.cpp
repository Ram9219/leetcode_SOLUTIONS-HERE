class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return true;
        //         }
             
        //     }
        // }
        // return false;

        unordered_set<int>ans;
        for(int i:nums){
            if(ans.count(i)){
                return true; // that means the duplicates found 
            }
            ans.insert(i);
        }
        return false;
    }
};