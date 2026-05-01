class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        int ans=-1;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                  continue;
            int step = 0;
            int node = i;
            unordered_map<int, int> mp;
            while (node != -1) {
                if (vis[node]) {
                    if (mp.find(node) != mp.end()) {
                        ans = max(ans, step - mp[node]);
                    }
                    break;
                }
               vis[node] = 1;
            mp[node] = step++;
            node = edges[node]; 
            }
        }
        return ans;
    }
};