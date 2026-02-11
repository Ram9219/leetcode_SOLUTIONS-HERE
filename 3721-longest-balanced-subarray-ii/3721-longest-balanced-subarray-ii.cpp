class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> firstOcc;

        int even = 0, odd = 0;
        int ans = 0;

        firstOcc[0] = -1;

        for(int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;

            if(freq[nums[i]] == 1) {
                if(nums[i] % 2 == 0)
                    even++;
                else
                    odd++;
            }

            int diff = even - odd;

            if(firstOcc.count(diff))
                ans = max(ans, i - firstOcc[diff]);
            else
                firstOcc[diff] = i;
        }

        return ans;
    }
};
