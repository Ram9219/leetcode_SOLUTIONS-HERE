class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> reach(n, vector<bool>(n, false));
        for (auto e : prerequisites) {
            reach[e[0]][e[1]] = true;
        }
        // floyed woorshel laga dop

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }
        }
        vector<bool> ans;
        for (auto q : queries) {
            ans.push_back(reach[q[0]][q[1]]);
        }
        return ans;
    }
};