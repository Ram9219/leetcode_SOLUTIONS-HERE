#define pb push_back
class Solution {

public:
    vector<vector<int>> ans;
    void dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& path) {
        path.pb(node);
        if (node == dest) {
            ans.pb(path);
            path.pop_back();
            return;
        }
        for (auto it : adj[node]) {
            dfs(it, dest, adj, path);
        }
        path.pop_back(); // for backtrack
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, graph.size() - 1, graph, path);
        return ans;
    }
};