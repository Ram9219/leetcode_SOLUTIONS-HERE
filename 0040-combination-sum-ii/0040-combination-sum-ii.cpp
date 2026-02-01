class Solution {
    void helper(vector<int>& arr, int i,
                vector<vector<int>>& ans,
                vector<int>& comb,
                int target) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (i >= arr.size() || target < 0) return;

        // INCLUDE current element
        comb.push_back(arr[i]);
        helper(arr, i + 1, ans, comb, target - arr[i]);
        comb.pop_back();

        // EXCLUDE current element (skip duplicates)
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;

        helper(arr, i + 1, ans, comb, target);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());   

        vector<vector<int>> ans;
        vector<int> comb;

        helper(nums, 0, ans, comb, target);
        return ans;
    }
};
