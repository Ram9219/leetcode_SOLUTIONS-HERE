class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto&e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==n)return true;
        return false;
    }
};