class Solution {
public:
    int dp[1001][1002];
    int lcs(string a, string b, int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string x = s;
        reverse(begin(x), end(x));
        string b = x;
        return n - lcs(s, b, n);
    }
};