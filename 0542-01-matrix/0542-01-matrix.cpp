class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)),
            dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        // step 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        // step 2
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [pos, steps] = q.front();
            int row = pos.first;
            int col = pos.second;
            q.pop();
            dist[row][col] = steps;
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                    !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return dist;
    }
};