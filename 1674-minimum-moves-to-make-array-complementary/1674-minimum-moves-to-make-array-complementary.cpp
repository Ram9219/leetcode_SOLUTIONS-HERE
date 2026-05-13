class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            int sum = a + b;

            // Initially 2 moves for all
            diff[2] += 2;

            // One move range starts
            diff[low] -= 1;

            // Zero move at exact sum
            diff[sum] -= 1;

            // Back to one move
            diff[sum + 1] += 1;

            // Back to two moves
            diff[high + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;

        for (int s = 2; s <= 2 * limit; s++) {

            cur += diff[s];

            ans = min(ans, cur);
        }

        return ans;
    }
};