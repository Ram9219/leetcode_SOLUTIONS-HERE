class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        // pahla kaam graph banao
        vector<pair<int, int>>adj[n];
        for (auto& e : flights) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        // aab ham yek priority queue le lete hai jissse ki ham minimum cost  ko
        // nikal sake  {stops,{node,cost}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)continue;
            for (auto& it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (cost + wt < dist[adjnode] && stops <= k) {
                    dist[adjnode] = cost + wt;
                    pq.push({stops + 1, {adjnode, cost + wt}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};