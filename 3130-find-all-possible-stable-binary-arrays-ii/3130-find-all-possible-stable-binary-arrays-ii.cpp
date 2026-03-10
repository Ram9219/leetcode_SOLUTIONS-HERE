class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j][0] -> i zeros, j ones, ends with 0
        // dp[i][j][1] -> i zeros, j ones, ends with 1
        // Using vector of vector for clarity; can be 1D for space optimization
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        // Base cases: single blocks of 0s or 1s within the limit
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                // Transition for dp0[i][j] (ending in 0)
                // It must follow a state ending in 1, or be a new block of 0s
                // Formula: dp0[i][j] = dp0[i-1][j] + dp1[i-1][j] - dp1[i-limit-1][j]
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % MOD;
                if (i > limit) {
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + MOD) % MOD;
                }

                // Transition for dp1[i][j] (ending in 1)
                // It must follow a state ending in 0, or be a new block of 1s
                // Formula: dp1[i][j] = dp1[i][j-1] + dp0[i][j-1] - dp0[i][j-limit-1]
                dp1[i][j] = (dp1[i][j - 1] + dp0[i][j - 1]) % MOD;
                if (j > limit) {
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + MOD) % MOD;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};