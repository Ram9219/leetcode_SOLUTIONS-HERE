class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0;
        int cur = 0;

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than required
            if (cur < minimum) {
                ans += (minimum - cur);
                cur = minimum;
            }
            cur -= actual;
        }

        return ans;
    }
};