
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int &count) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        count++;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis,count);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count=0;
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, vis, count);
                    cnt=max(count,cnt);
                }
            }
        }
        return cnt;
    }
};