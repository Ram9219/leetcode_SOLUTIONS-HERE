class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        // store all indices of same value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                    return steps;

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = 1;
                    q.push(curr - 1);
                }
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = 1;
                    q.push(curr + 1);
                }

                // same vjumps
                for (auto next : mp[arr[curr]]) {

                    if (!visited[next]) {
                        visited[next] = 1;
                        q.push(next);
                    }
                }

                // important
                mp[arr[curr]].clear();
            }

            steps++;
        }

        return -1;
    }
};