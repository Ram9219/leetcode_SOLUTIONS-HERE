class Solution {
private:
    // for(auto&x:adj[node]){
    //     if(!vis[x]){
    //         dfs(x,adj,vis);
    //     }
    // }//maine directly adjacency list use kar liya is wjah se ye nahi chalega
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[node][i] == 1 && !vis[i]) {
                dfs(i, adj, vis);
            }
        }
    }
void bfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<adj.size();i++){
            if(!vis[i]&& adj[cur][i]==1){
              vis[i]=1;
              q.push(i);
            }
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        // vis[0]=1;
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!vis[i]) {
                count++;
                bfs(i, isConnected, vis);
            }
        }
        return count;
    }
};