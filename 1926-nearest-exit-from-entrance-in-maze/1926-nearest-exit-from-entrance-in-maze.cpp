class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<pair<int,int>,int>>q;//entrance[0],entrance[1],steps
        q.push({{entrance[0],entrance[1]},0});
        maze[entrance[0]][entrance[1]]='+';
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && maze[nrow][ncol]=='.'){
                    if(nrow==0 || nrow == n-1 ||ncol==0 || ncol == m-1){
                        return steps+1;
                    }
                  maze[nrow][ncol]='+';
                        q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return -1;
    }
};