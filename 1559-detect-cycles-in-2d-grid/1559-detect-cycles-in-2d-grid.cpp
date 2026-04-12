class Solution {
private:
    bool bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;
        // {{row,col}, {parent_row, parent_col}}

        vis[row][col] = 1;
        q.push({{row, col}, {-1, -1}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int ro = front.first.first;
            int co = front.first.second;
            int parent_row = front.second.first;
            int parent_col = front.second.second;

            for (int i = 0; i < 4; i++) {
                int nrow = ro + drow[i];
                int ncol = co + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == grid[ro][co]) {

                    if (!vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {ro, co}});
                    }
                    else if (nrow != parent_row || ncol != parent_col) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (bfs(i, j, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};