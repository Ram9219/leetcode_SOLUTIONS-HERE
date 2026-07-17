
class Disjoint {
public:
    vector<int> parent, rank;
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
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            rank[pu] += rank[pv];
        } else {
            parent[pv] = pu;
            rank[pv] += rank[pu];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.Union_By_Rank(i, mp[mail]);
                }
            }
        }
        vector<string> merge[n];
        for (auto& it : mp) {
            string mail = it.first;
            int node = ds.ult_parent(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0)
                continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& it : merge[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};