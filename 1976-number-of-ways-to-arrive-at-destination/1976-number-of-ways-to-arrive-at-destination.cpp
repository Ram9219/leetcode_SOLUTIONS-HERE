class Solution {
    //isme shortest wala criteria lagega 
public:
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto&e:roads){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        vector<long long>dist(n,LLONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            int node=it.second;
            if(dis>dist[node])continue;
            for(auto& it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    pq.push({dis+wt,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;

    }
};