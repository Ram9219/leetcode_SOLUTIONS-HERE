class Disjoint {
public:
    vector<int> rank, parent;
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
    bool Find_Union_By_Rank(int u, int v) {
        int pu = ult_parent(u);
        int pv = ult_parent(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1 ;j<n ;j++){
                int cost=abs(points[i][0]-points[j][0])+
                abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});//cost ,u ,v
            }
        }
        sort(begin(edges),end(edges));
        Disjoint ds(n);
        int ans=0;
        int count=0;//for finding the mst cycle 
        for(auto &e:edges){
            int cost=e[0];
            int u=e[1];
            int v=e[2];
            if(ds.Find_Union_By_Rank(u,v)){
                ans+=cost;
                count++;
            }
            if(count==n-1)break;

        }
        return ans;
    }
};