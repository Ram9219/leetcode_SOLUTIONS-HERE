class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();
        int target =total / 2; // kyunki mujhe target ko part me divide karna hai
        if(total%2)return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};