class Solution {

public:
    int dp[1002][1002];
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        if (dp[row][col]) {
            return dp[row][col];
        }
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                grid[nrow][ncol] > grid[row][col]) {
                ans = max(ans, 1 + dfs(nrow, ncol, grid));
            }
        }
        return dp[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                res = max(res, dfs(i, j, grid));
            }
        }
        return res;
    }
};