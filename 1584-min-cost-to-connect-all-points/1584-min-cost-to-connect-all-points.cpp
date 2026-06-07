class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& houses) {
        // code here
        int n=houses.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});//{weight,node}
        int sum=0;
        while(!pq.empty()){
            auto[wt,node]=pq.top();
            pq.pop();
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            for(int i=0;i<n;i++){
                int newcost=abs(houses[node][0]-houses[i][0])+
                abs(houses[node][1]-houses[i][1]);
                pq.push({newcost,i});
            }
        }
        return sum;
    
    }
};