class Solution {

public:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<int>> vis;
    int dfs(int row, int col) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
            return 1;
        }
        if (vis[row][col]) {
            return 0;
        }
        vis[row][col] = 1;
        int peri = 0;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            peri += dfs(nrow, ncol);
        }

        return peri;
    }
    int islandPerimeter(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};