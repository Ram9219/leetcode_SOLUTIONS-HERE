class DSU {
public:
    vector<int> rank, parent;
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(begin(parent), end(parent), 0);
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void _union(int u, int v) {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ds._union(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                count++;
            }
        }
        return count;
    }
};