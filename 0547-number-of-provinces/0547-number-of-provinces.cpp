class DisjointSet{
public:
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int ult_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=ult_parent(parent[node]);
    }
    void find_Union(int u,int v){
        int pu=ult_parent(u);
        int pv=ult_parent(v);
        if(pu==pv)return;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet d(n);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    d.find_Union(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(d.ult_parent(i)==i){
                count++;
            }
        }
        return count;
    }
};