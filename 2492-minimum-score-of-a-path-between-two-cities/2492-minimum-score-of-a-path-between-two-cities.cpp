class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<pair<int, int>> adj[n + 1];
        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        queue<int> q;
        q.push(1);

        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;
        vis[1] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                ans = min(ans, it.second);
                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};