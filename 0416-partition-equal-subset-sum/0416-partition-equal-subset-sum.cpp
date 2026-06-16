class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int total=accumulate(begin(nums),end(nums),0);
        if(total%2)return false;
        int n=nums.size();
        int target=total/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int s=target;s>=num;s--){
                dp[s]=dp[s]|| dp[s-num];
            }
        }
        return dp[target];

    }
};