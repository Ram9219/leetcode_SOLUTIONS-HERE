class Disjoint {
public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(begin(parent), end(parent), 0);
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold,
                              vector<vector<int>>& queries) {

        Disjoint ds(n);
        vector<bool> ans;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = i + 1; j <= n; j++) {
        //         if (__gcd(i, j) > threshold) {
        //             ds.unite(i, j);
        //         }
        //     }
        // }
        for (int g = threshold + 1; g <= n; g++) {
            // Connect the first multiple (g) with all subsequent multiples (2g,
            // 3g, ...)
            for (int m = 2 * g; m <= n; m += g) {
                ds.unite(g, m);
            }
        }

        for (auto& q : queries) {
            ans.push_back(ds.find(q[0]) == ds.find(q[1]));
        }
        return ans;
    }
};