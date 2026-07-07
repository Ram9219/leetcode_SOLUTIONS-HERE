class Solution {
private:
// A connected component is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.

    void dfs(int node, vector<int> adj[], vector<int>& vis, int& nodecount,
             int& edgecount) {
        vis[node] = 1;
        nodecount++;
        for (auto& it : adj[node]) {
            edgecount++;
            if (!vis[it]) {
                dfs(it, adj, vis, nodecount, edgecount);
            }
        }
    }

public:
    int countCompleteComponents(int m, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[m + 1];
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(m + 1, 0);
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                int nodecount = 0;
                int edgecount = 0;
                dfs(i, adj, vis, nodecount, edgecount);
                edgecount /= 2;
                if (edgecount == (nodecount * (nodecount - 1) / 2)) {
                    count++;
                }
            }
        }
        return count;
    }
};