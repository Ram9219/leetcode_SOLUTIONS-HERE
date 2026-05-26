class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int ult_Parent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = ult_Parent(parent[node]);
    }
    void find_Union_By_Rank(int u, int v) {
        int pu = ult_Parent(u);
        int pv = ult_Parent(v);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;
        int extra = 0;
        int m = connections.size();
        DisjointSet d(n);
        for (int i = 0; i < m; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if (d.ult_Parent(u) == d.ult_Parent(v)) {
                extra++;
            } else {
                d.find_Union_By_Rank(u, v);
            }
        }
        for (int i = 0; i < n; i++) {
            if (d.ult_Parent(i) == i)
                count++;
        }
        int ans = count - 1;
        if (extra >= ans) {
            return ans;
        } else
            return -1;
    }
};