class Solution {
    //short trick to find the all neighours near ou 
    //for(int delta_row=-1;delta_row<=1;delta_row++){
    //     for(int delta_col=-1;delta_col>=1;delta_col++){
    //         int n_row=row+delta_row;
    //         int n_col=col+delta_col;
    //     }
    // }
    private:
    void bfs(int ro,int co,vector<vector<int>>&vis,vector<vector<char>>&adj){
        vis[ro][co]=1;
        int n=adj.size();
        int m=adj[0].size(); 
    queue<pair<int,int>>q;
    q.push({ro,co});
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int row=front.first;
        int col=front.second;
       //i hvae to traverse i mean to find the whole neighnours 
       for(int drow=-1;drow<=1;drow++){
        for(int dcol=-1;dcol<=1;dcol++){
            if(abs(drow)+abs(dcol)!=1){
                continue;
            }
            int nrow=row+drow;
            int ncol=col+dcol;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='1' && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
       }
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    
    }
};