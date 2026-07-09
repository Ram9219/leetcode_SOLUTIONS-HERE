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
    void Rank_By_Union(int u, int v) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        // if(nums[i]-nums[i-1]<=maxdiff)then  unite kardo
        Disjoint ds(n);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ds.Rank_By_Union(i, i - 1);
            }
        }
        // query per aab mujhe dsu perform karn ahia
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(ds.ult_parent(q[0]) == ds.ult_parent(q[1]));
        }
        return ans;
    }
};