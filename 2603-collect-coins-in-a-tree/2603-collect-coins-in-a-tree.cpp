class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> indeg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }

        queue<int> q;

        // Step 1: Remove all leaf nodes having no coin
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1 && coins[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            indeg[node]--;

            for (int nxt : adj[node]) {
                if (indeg[nxt] == 0)
                    continue;

                indeg[nxt]--;

                if (indeg[nxt] == 1 && coins[nxt] == 0)
                    q.push(nxt);
            }
        }

        // Step 2: Remove leaves twice
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1)
                q.push(i);
        }

        for (int round = 0; round < 2; round++) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                indeg[node]--;

                for (int nxt : adj[node]) {
                    if (indeg[nxt] == 0)
                        continue;

                    indeg[nxt]--;

                    if (indeg[nxt] == 1)
                        q.push(nxt);
                }
            }
        }

        int rem = 0;

        for (int i = 0; i < n; i++) {
            if (indeg   [i] > 0)
                rem++;
        }

        return rem == 0 ? 0 : (rem - 1) * 2;
    }
};