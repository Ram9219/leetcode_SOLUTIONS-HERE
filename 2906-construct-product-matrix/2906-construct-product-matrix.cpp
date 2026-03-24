class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        vector<long long> nums;
        // first inmsert the element to the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        int size=nums.size();
        vector<long long> suffix(size, 1), prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * nums[i - 1]) % mod;
        }
        // suffix product
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * nums[i + 1]) % mod;
        }
        // now will build the ans
         vector<vector<int>> ans(n,vector<int>(m));
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (prefix[index] * suffix[index]) % mod;
                index++;
            }
        }
        return ans;
    }
};