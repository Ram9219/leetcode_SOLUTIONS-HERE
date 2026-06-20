class Disjoint {
public:
    vector<int> parent, rank;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int ult_parent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = ult_parent(parent[node]);
    }
    bool FindUnion_By_Rank(int u, int v) {
        int pu = ult_parent(u);
        int pv = ult_parent(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint ds(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (!ds.FindUnion_By_Rank(u, v)) {
                return e;
            }
        }
        return {};
    }
};