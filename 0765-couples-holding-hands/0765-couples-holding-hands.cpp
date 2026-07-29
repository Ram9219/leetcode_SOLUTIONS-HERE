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
    int minSwapsCouples(vector<int>& row) {

        int n=row.size()/2;
        Disjoint ds(n);
        for(int i=0;i<row.size();i+=2){
            int c1=row[i]/2;
            int c2=row[i+1]/2;
            ds.unite(c1,c2);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n ;i++){
            mp[ds.find(i)]++;
        }
        int ans=0;
        for(auto &it:mp){
            ans+=it.second-1;
        }
        return ans;
    }
};