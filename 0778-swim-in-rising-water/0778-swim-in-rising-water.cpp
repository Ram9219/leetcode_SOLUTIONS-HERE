class Disjoint{
    public:
    vector<int>rank,parent;
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        iota(begin(parent),end(parent),0);
    }
    int find(int node){
        if(node==parent[node])return node;
        return parent[node]=find(parent[node]);
    }
    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = n;
        Disjoint ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> ans(n * n);
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[grid[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < n * n; i++) {
            auto[row, col] = ans[i];
            int node = row * n + col;
            vis[row][col]=1;
            for (int j = 0; j < 4; j++) {
                int nrow = row + drow[j];
                int ncol = col + dcol[j];
                if (nrow < n && nrow >= 0 && ncol < m &&
                    ncol >= 0  &&vis[nrow][ncol]) {
                    int adjnode = nrow * n + ncol;
                    ds.unite(node, adjnode);
                }
            }
            if (ds.find(0) == ds.find(n * n - 1)) {
                return i;
            }
        }
        return -1;
    }
};