class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // cuts[i] stores the minimum cuts needed for substring s[0...i]
        vector<int> cuts(n);
        // dp[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            // Maximum possible cuts for s[0...i] is i cuts
            int min_cuts = i; 
            
            for (int j = 0; j <= i; j++) {
                // s[j...i] is a palindrome if characters match AND
                // either the inner substring is valid or length is <= 2
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    
                    // If s[0...i] is a palindrome, 0 cuts are needed
                    // Otherwise, it is 1 cut + minimum cuts needed for s[0...j-1]
                    min_cuts = (j == 0) ? 0 : min(min_cuts, cuts[j - 1] + 1);
                }
            }
            cuts[i] = min_cuts;
        }

        return cuts[n - 1];
    }
};
