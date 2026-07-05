class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X')
                    continue;

                if (i == n - 1 && j == n - 1)
                    continue;

                int mx = -1;
                long long cnt = 0;

                // Down
                if (i + 1 < n && score[i + 1][j] != -1) {
                    if (score[i + 1][j] > mx) {
                        mx = score[i + 1][j];
                        cnt = ways[i + 1][j];
                    } else if (score[i + 1][j] == mx) {
                        cnt = (cnt + ways[i + 1][j]) % mod;
                    }
                }

                // Right
                if (j + 1 < n && score[i][j + 1] != -1) {
                    if (score[i][j + 1] > mx) {
                        mx = score[i][j + 1];
                        cnt = ways[i][j + 1];
                    } else if (score[i][j + 1] == mx) {
                        cnt = (cnt + ways[i][j + 1]) % mod;
                    }
                }

                // Diagonal
                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1) {
                    if (score[i + 1][j + 1] > mx) {
                        mx = score[i + 1][j + 1];
                        cnt = ways[i + 1][j + 1];
                    } else if (score[i + 1][j + 1] == mx) {
                        cnt = (cnt + ways[i + 1][j + 1]) % mod;
                    }
                }

                if (mx == -1)
                    continue;

                score[i][j] = mx;
                ways[i][j] = cnt;

                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    score[i][j] += board[i][j] - '0';
                }
            }
        }

        if (score[0][0] == -1)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};