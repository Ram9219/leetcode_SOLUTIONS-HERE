class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<int>& vis) {
        
        // out of bounds
        if(start < 0 || start >= arr.size())
            return false;
        
        // already visited
        if(vis[start])
            return false;
        
        // found 0
        if(arr[start] == 0)
            return true;
        
        vis[start] = 1;
        
        // jump forward or backward
        return dfs(arr, start + arr[start], vis) ||
               dfs(arr, start - arr[start], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return dfs(arr, start, vis);
    }
};