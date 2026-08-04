class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st(begin(nums), end(nums));
        int mn = *min_element(begin(nums), end(nums));
        int mx = *max_element(begin(nums), end(nums));
        for (int i = mn; i <= mx; i++) {
            if (!st.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};