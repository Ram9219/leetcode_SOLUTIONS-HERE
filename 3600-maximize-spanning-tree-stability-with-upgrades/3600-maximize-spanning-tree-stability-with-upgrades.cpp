#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent;
    int components;
    DSU(int n) {
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        components = n;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool check(int X, int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int upgrades_used = 0;
        int must_edges_count = 0;
        int total_must_in_input = 0;

        // 1. Mandatory Edges
        for (const auto& e : edges) {
            if (e[3] == 1) {
                total_must_in_input++;
                if (e[2] < X) return false; // Must edge fails stability
                if (dsu.unite(e[0], e[1])) must_edges_count++;
            }
        }
        
        // Spanning tree check: must edges must not form a cycle
        if (must_edges_count < total_must_in_input) return false;

        // 2. Optional Edges (No upgrade needed)
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= X) {
                dsu.unite(e[0], e[1]);
            }
        }

        // 3. Optional Edges (Upgrade needed)
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && 2 * e[2] >= X) {
                if (dsu.unite(e[0], e[1])) {
                    upgrades_used++;
                }
            }
        }

        return dsu.components == 1 && upgrades_used <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 0, high = 200000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};