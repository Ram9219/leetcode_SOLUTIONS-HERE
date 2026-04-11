class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;
        int time=0;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    fresh++;
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
             time=max(time,t);
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&!vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    fresh--;
                }
            }
        }


       if(fresh>0)return -1;
        return time;

    }
};