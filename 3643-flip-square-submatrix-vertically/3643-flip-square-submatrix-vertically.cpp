class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // Traverse half rows of the k x k submatrix
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                // Swap top and bottom rows
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        
        return grid;
    }
};