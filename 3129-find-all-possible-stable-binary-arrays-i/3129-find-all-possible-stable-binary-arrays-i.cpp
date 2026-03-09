class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<long long>>> dp(
            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        dp[0][0][0] = dp[0][0][1] = 1;

        for(int z = 0; z <= zero; z++) {
            for(int o = 0; o <= one; o++) {

                for(int k = 1; k <= limit && z + k <= zero; k++) {
                    dp[z+k][o][0] = (dp[z+k][o][0] + dp[z][o][1]) % MOD;
                }

                for(int k = 1; k <= limit && o + k <= one; k++) {
                    dp[z][o+k][1] = (dp[z][o+k][1] + dp[z][o][0]) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};