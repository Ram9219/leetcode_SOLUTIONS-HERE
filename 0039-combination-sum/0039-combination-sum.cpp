class Solution {
public:
    void get(vector<int>& arr, int i, int target,
             vector<int>& comb, vector<vector<int>>& ans) {

        // base cases
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        if (i == arr.size() || target < 0) {
            return;
        }

        // INCLUDE arr[i]
        comb.push_back(arr[i]);
        get(arr, i, target - arr[i], comb, ans);  // same index
        comb.pop_back();

        // EXCLUDE arr[i]
        get(arr, i + 1, target, comb, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        get(nums, 0, target, comb, ans);
        return ans;
    }
};
