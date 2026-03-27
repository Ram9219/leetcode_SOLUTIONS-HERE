class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newIndex;
                
                if (i % 2 == 0) {
                    // left shift
                    newIndex = (j + k) % n;
                } else {
                    // right shift
                    newIndex = (j - k % n + n) % n;
                }
                
                if (mat[i][j] != mat[i][newIndex])
                    return false;
            }
        }
        
        return true;
    }
};