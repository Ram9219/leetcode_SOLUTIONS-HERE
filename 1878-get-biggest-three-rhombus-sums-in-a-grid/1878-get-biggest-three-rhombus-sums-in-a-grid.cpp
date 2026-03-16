class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> s;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                s.insert(grid[r][c]); // size 0 rhombus

                for (int k = 1;; k++) {

                    int r2 = r + 2 * k;
                    int c1 = c - k;
                    int c2 = c + k;

                    if (r2 >= m || c1 < 0 || c2 >= n)
                        break;

                    int sum = 0;

                    int x = r, y = c;
                    for (int i = 0; i < k; i++)
                        sum += grid[x + i][y + i];

                    x = r + k, y = c + k;
                    for (int i = 0; i < k; i++)
                        sum += grid[x + i][y - i];

                    x = r + 2 * k, y = c;
                    for (int i = 0; i < k; i++)
                        sum += grid[x - i][y - i];

                    x = r + k, y = c - k;
                    for (int i = 0; i < k; i++)
                        sum += grid[x - i][y + i];

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto x : s) {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};