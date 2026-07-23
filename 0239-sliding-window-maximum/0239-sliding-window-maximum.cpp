class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int i = 0;
        vector<int> ans;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            while (!q.empty() && q.back().first < nums[j]) {
                q.pop_back();
            }

            q.push_back({nums[j], j});

            if (j - i + 1 < k) {
                continue;
            } else {
                ans.push_back(q.front().first);
                if (q.front().second == i) {
                    q.pop_front();
                }
                i++;
            }
        }
        return ans;
    }
};