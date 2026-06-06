class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int>adj[], vector<int>& vis,
             vector<int>& tin, vector<int>& low, vector<vector<int>>& ans) {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                // it as index ,node as parent ,adj,
                dfs(it, node,adj, vis, tin, low, ans);
                low[node] = min(low[it], low[node]);
                if (low[it] >tin[node]) {
                    ans.push_back({node,it});
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n), low(n), vis(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, adj, vis, tin, low, ans);
        return ans;
    }
};