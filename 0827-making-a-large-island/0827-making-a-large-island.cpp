class DisjointSet{
    public:
    vector<int>size,rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int ult_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=ult_parent(parent[node]);
    }
    void size_By_union(int u,int v){
        int pu=ult_parent(u);
        int pv=ult_parent(v);
        if(pu==pv)return ;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    void rank_By_Union(int u ,int v){
        int pu=ult_parent(u);
        int pv=ult_parent(v);
        if(pu==pv)return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
             parent[pv]=pu;
             rank[pu]++;
        }
    }
};

class Solution {
public:
bool valid(int nrow ,int ncol,int n){
    return nrow<n && nrow>=0 && ncol<n && ncol>=0;
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        //step: 1--> connect all the component 
        for(int row=0;row<n ;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(valid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        int nodeno=row*n+col;
                        int adjnode=nrow*n+ncol;
                        ds.size_By_union(nodeno,adjnode);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                set<int>st;
                int totalsize=0;
                int drow[]={-1,0,1,0};
                int dcol[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(valid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        st.insert(ds.ult_parent(nrow*n+ncol));
                    }
                }
                for(auto &it:st){

                    totalsize+=ds.size[it];
                }
                mx=max(mx,totalsize+1);
              
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.ult_parent(i)]);
        }
        return mx;
    }
};