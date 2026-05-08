class Solution {
public:
    vector<int> sieve(int mx) {

        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= mx; j += i) {

                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    bool isPrime(int x, vector<int>& spf) { return x > 1 && spf[x] == x; }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf = sieve(mx);

        unordered_map<int, vector<int>> bucket;

        // build bucket
        for (int i = 0; i < n; i++) {

            int val = nums[i];

            while (val > 1) {

                int p = spf[val];

                bucket[p].push_back(i);

                while (val % p == 0) {
                    val /= p;
                }
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            // left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // teleport
            if (isPrime(nums[i], spf)) {

                int p = nums[i];

                for (auto idx : bucket[p]) {

                    if (dist[idx] == -1) {

                        dist[idx] = d + 1;
                        q.push(idx);
                    }
                }

                // avoid repeated work
                bucket[p].clear();
            }
        }

        return -1;
    }
};