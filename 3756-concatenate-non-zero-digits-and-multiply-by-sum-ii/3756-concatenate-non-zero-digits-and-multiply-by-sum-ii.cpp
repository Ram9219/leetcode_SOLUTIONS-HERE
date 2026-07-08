class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Original index -> compressed index
        vector<int> idx(n, -1);

        // next/prev non-zero position
        vector<int> nextNZ(n, -1), prevNZ(n, -1);

        vector<int> digit;

        // Build compressed array
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                idx[i] = k++;
                digit.push_back(s[i] - '0');
            }
        }

        // next non-zero
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                last = i;
            nextNZ[i] = last;
        }

        // previous non-zero
        last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                last = i;
            prevNZ[i] = last;
        }

        int m = digit.size();

        // powers of 10
        vector<long long> pw(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        // prefix digit sum
        vector<long long> prefSum(m + 1, 0);

        // prefix concatenated value
        vector<long long> prefVal(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int L = q[0];
            int R = q[1];

            int leftPos = nextNZ[L];
            int rightPos = prevNZ[R];

            if (leftPos == -1 || rightPos == -1 || leftPos > rightPos) {
                ans.push_back(0);
                continue;
            }

            int l = idx[leftPos];
            int r = idx[rightPos];

            int len = r - l + 1;

            long long value =
                (prefVal[r + 1] - prefVal[l] * pw[len] % MOD + MOD) % MOD;

            long long sumDigits = prefSum[r + 1] - prefSum[l];

            ans.push_back((value * sumDigits) % MOD);
        }

        return ans;
    }
};