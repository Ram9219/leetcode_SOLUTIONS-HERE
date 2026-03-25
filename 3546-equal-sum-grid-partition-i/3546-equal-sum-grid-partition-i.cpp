class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // total sum
        for (auto &row : grid) {
            for (auto &val : row) {
                total += val;
            }
        }

        // if odd → not possible
        if (total % 2 != 0) return false;

        long long target = total / 2;

        // 🔹 Horizontal cut
        long long prefix = 0;
        for (int i = 0; i < m; i++) {
            long long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            prefix += rowSum;

            if (prefix == target && i != m - 1) {
                return true;
            }
        }

        // 🔹 Vertical cut
        prefix = 0;
        for (int j = 0; j < n; j++) {
            long long colSum = 0;
            for (int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            prefix += colSum;

            if (prefix == target && j != n - 1) {
                return true;
            }
        }

        return false;
    }
};