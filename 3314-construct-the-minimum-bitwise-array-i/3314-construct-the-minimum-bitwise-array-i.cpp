class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
            } else {
                // Find the lowest bit that is 0 in (p + 1)
                // This corresponds to the end of the trailing ones in p
                for (int i = 0; i < 31; ++i) {
                    if (!((p >> (i + 1)) & 1)) {
                        // Clear the i-th bit
                        ans.push_back(p ^ (1 << i));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};