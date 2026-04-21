class Solution {
    private:
    void dfs(int row,int col,vector<vector<char>>&adj,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n=adj.size();
        int m=adj[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
            &&adj[nrow][ncol]=='O'){
                dfs(nrow,ncol,adj,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //first & last row traversal 
        for(int i=0; i<m ;i++){
            if(!vis[0][i] && grid[0][i]=='O'){
                dfs(0,i,grid,vis);
            }
            if(!vis[n-1][i] && grid[n-1][i]=='O'){
                dfs(n-1,i,grid,vis);
            }
        }
        //firs & last col traversal 
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]=='O'){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O'){
                dfs(i,m-1,grid,vis);
            }
        }
        //entire grid traverse
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }

        
    }
};