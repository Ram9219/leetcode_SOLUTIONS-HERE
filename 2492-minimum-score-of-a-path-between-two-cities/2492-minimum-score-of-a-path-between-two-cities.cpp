class Disjoint {
public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(begin(parent), end(parent), 0);
    }
    int ult_parent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = ult_parent(parent[node]);
    }
    void Union_By_Rank(int u, int v) {
        int pu = ult_parent(u);
        int pv = ult_parent(v);
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
    int minScore(int n, vector<vector<int>>& roads) {
        Disjoint ds(n);
        int ans = INT_MAX;
        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            ds.Union_By_Rank(u, v);
        }

         for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            int p = ds.ult_parent(1);
            if (ds.ult_parent(u) == p) {
                ans = min(ans, wt);
            }
        }
    
        return ans;
    }
};