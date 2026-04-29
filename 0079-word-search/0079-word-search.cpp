class Solution {
private:
    bool dfs(int row, int col, int idx, vector<vector<char>>& grid,
             string& word) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        if (idx == word.size())
            return true;
        // mismatch check boundary check
        if (row <0 || row >= n || col < 0 || col >= m ||
            grid[row][col] != word[idx]) {
            return false;
        }

        char temp = grid[row][col];
        grid[row][col] = '#';
        //marking as a visited
         for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (dfs(nrow, ncol, idx + 1, grid, word)) {
                return true;
            }
        }
        grid[row][col] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};