class Disjoint {
public:
    vector<int> parent, rank, size;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1,1);
        iota(begin(parent), end(parent), 0);
    }
    int ult_parent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = ult_parent(parent[node]);
    }
    void size_union(int u, int v) {
    int pu = ult_parent(u);
    int pv = ult_parent(v);

    if (pu == pv) return;

    if (size[pu] < size[pv]) {
        parent[pu] = pv;
        size[pv] += size[pu];
    } else {
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}
   void Find_union_By_Rank(int u, int v) {
    int pu = ult_parent(u);
    int pv = ult_parent(v);

    if (pu == pv) return;

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    else if (rank[pv] < rank[pu]) {
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    else {
        parent[pv] = pu;
        rank[pu]++;
        size[pu] += size[pv];
    }
}
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        Disjoint ds(n * m);

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0)
                    continue;

                int node = i * m + j;

                for (auto& d : dir) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                        grid[ni][nj] == 1) {
                        int adj = ni * m + nj;
                        ds.Find_union_By_Rank(node, adj);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int p = ds.ult_parent(i * m + j);
                    ans = max(ans, ds.size[p]);
                }
            }
        }

        return ans;
    }
};