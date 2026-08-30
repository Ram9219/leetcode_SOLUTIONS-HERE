class Disjoint{
public:
    vector<int> rank, parent, size;

    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node){
        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;

        Disjoint ds(n);

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){

            // duplicate
            if(mp.count(nums[i]))
                continue;

            mp[nums[i]] = i;

            // nums[i] - 1 exists
            if(mp.count(nums[i] - 1)){
                ds.unite(i, mp[nums[i] - 1]);
            }

            // nums[i] + 1 exists
            if(mp.count(nums[i] + 1)){
                ds.unite(i, mp[nums[i] + 1]);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(ds.find(i) == i)
                ans = max(ans, ds.size[i]);
        }

        return ans;
    }
};