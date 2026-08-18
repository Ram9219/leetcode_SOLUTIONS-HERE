#define deepak pair<int, int>
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();
        int finalmask = (1 << n) - 1;
        queue<deepak> q;
        vector<vector<int>> vis(n, vector<int>((1 << n), 0));

        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            vis[i][mask] = 1;
        }
        int steps = 0;
        while (!q.empty()) {
            int x = q.size();
            for (int i = 0; i < x; i++) {
                auto [node, mask] = q.front();
                q.pop();
                if (mask == finalmask) {
                    return steps;
                }
                for (auto& it : graph[node]) {
                    int newmask = mask |(1 << it);
                    if (!vis[it][newmask]) {
                        vis[it][newmask] = 1;
                        q.push({it, newmask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};