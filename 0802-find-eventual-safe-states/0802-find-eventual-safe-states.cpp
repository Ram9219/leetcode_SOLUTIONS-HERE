class Solution {
    private:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,check)==true){
                    return true;
                }
            }
            else if(pathvis[it]==1)return true;
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pathvis(n,0),check(n,0),ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};