class Solution {
private:
    bool detect(int ro, int co, vector<vector<char>>& adj,
                vector<vector<int>>& vis) {
        vis[ro][co] = 1;
        int n = adj.size();
        int m = adj[0].size();
        queue<pair<pair<int, int>, pair<int, int>>> q;
        //{{row,col},{parent_row,parent_col}}
        q.push({{ro, co},
                {-1, -1}}); // intially parent_row=-1 and parent_col=-1 rahengge
                            // because we dont know that ki kaha se aay ahai
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int prow = q.front().second.first;
            int pcol = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = dcol[i] + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    adj[nrow][ncol] == adj[row][col]) {
                    if (!vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {row, col}});
                    }
                    else if (nrow != prow || ncol != pcol){
                        return true;
                    }
                } 
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& adj) {
        int n = adj.size();
        int m = adj[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (detect(i, j, adj, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};