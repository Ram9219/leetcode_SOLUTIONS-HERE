class Solution {
public:
//agr length return karni hoti to seedha ham (n+m)-lcs(a,b,n,m); kar sakte hai 
    int dp[1001][1002];
    int lcs(string a, string b, int n, int m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string a, string b) {
        memset(dp, 0, sizeof(dp));
        int n=a.size(),m=b.size();
        lcs(a,b,n,m);
        int i = n;
        int j = m;
        string ans = "";

        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                ans += a[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += a[i - 1];
                i--;
            } else {
                ans += b[j - 1];
                j--;
            }
        }
        while (i > 0) {
            ans += a[--i];
        }
        while (j > 0) {
            ans += b[--j];
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};