class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n), premax(n);

        // prefix maximum
        premax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], nums[i]);
        }

        int suff = INT_MAX;

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            if (premax[i] > suff) {

                if (i == n - 1)
                    ans[i] = premax[i];
                else
                    ans[i] = ans[i + 1];

            } else {
                ans[i] = premax[i];
            }

            suff = min(suff, nums[i]);
        }

        return ans;
    }
};