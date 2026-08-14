class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> freq;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while (freq.size() > 2) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                   freq.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};