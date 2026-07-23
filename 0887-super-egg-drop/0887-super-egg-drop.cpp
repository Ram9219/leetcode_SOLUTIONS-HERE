class Solution {
public:
    int dp[101][10002];
    int solve(int e, int f) {
        // e->egg
        // f-->floor
        if (e == 1) {
            return f;
        }
        if (f == 0 || f == 1)
            return f;
        if (dp[e][f] != -1) {
            return dp[e][f];
        }
        int ans = INT_MAX;
        // for (int k = 1; k <= f; k++) {
        //     int left = solve(e - 1, k - 1);
        //     int right = solve(e, f - k);
        //     // mcm style subproblem solved now temp
        //     int temp = 1 + max(left, right);
        //     ans = min(ans, temp);
        // }
        int i = 1, j = f;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            int left = solve(e - 1, mid - 1);
            int right = solve(e, f - mid);
            int temp = 1 + max(left, right);
            ans = min(ans, temp);
            if (left > right) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};