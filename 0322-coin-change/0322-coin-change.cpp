class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto& x:coins){
                if(i-x>=0){
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        return dp[amount]==1e9?-1:dp[amount];
    }
};