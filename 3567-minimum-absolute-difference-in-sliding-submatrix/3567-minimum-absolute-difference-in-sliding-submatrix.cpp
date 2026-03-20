class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> temp;

                // collect elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }

                // sort
                sort(temp.begin(), temp.end());

                // remove duplicates
                temp.erase(unique(temp.begin(), temp.end()), temp.end());

                // if only one distinct value
                if (temp.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                // find min difference
                int minDiff = INT_MAX;
                for (int t = 1; t < temp.size(); t++) {
                    minDiff = min(minDiff, temp[t] - temp[t - 1]);
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};