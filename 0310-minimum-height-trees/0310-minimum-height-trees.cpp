class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> adj[n];
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        int rem = n;
        while (rem > 2) {
            int size = q.size();
            rem -= size;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                for (auto x : adj[node]) {
                    degree[x]--;
                    if (degree[x] == 1) {
                        q.push(x);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};