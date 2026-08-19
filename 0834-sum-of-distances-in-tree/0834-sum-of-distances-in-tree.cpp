#define ll int
#define pb push_back
class Solution {
private:
    int dfs(int node, vector<vector<ll>>& adj, int contribution, int parent,
            vector<ll>& count) {
        int sum = contribution;
        for (auto& it : adj[node]) {

            if (it != parent) {
                sum += dfs(it, adj, contribution + 1, node, count);
                count[node] += count[it];
            }
        }
        count[node] += 1;
        return sum;
    }
    void finalDFS(int node, vector<vector<ll>>& adj, int parent,
                  vector<ll>& count, vector<ll>& res) {
        for (auto& it : adj[node]) {
            if(it!=parent){
                res[it] = res[node] + count.size() - 2 * count[it];
                finalDFS(it,adj,node,count,res);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<ll> ans(n), count(n);
        vector<vector<ll>> adj(n);
        for (auto& e : edges) {
            ll u = e[0];
            ll v = e[1];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ans[0] = dfs(0, adj, 0, -1,count);
        finalDFS(0, adj, -1, count, ans);

        return ans;
    }
};