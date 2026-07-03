class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indeg(n, 0);

        int mxWt = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            indeg[v]++;
            mxWt = max(mxWt, wt);
        }

        // Topological Sort
        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto& it : adj[node]) {
                indeg[it.first]--;
                if (indeg[it.first] == 0)
                    q.push(it.first);
            }
        }

        auto check = [&](int limit) {
            vector<long long> dp(n, LLONG_MAX);

            dp[0] = 0;

            for (auto& u : topo) {

                if (dp[u] == LLONG_MAX)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto& it : adj[u]) {

                    int v = it.first;
                    int wt = it.second;

                    if (wt < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    dp[v] = min(dp[v], dp[u] + wt);
                }
            }

            return dp[n - 1] <= k;
        };

        int lo = 0;
        int hi = mxWt;
        int ans = -1;

        while (lo <= hi) {

            int mid = (lo + hi) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};