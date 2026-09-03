class Solution {
public:
    bool canMakeEven(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) { // odd
                bool ok = false;
                for (int j = 0; j < i; j++) {
                    if (nums[j] % 2 == 1) { // odd smaller
                        ok = true;
                        break;
                    }
                }
                if (!ok) return false;
            }
        }
        return true;
    }

    bool canMakeOdd(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) { // even
                bool ok = false;
                for (int j = 0; j < i; j++) {
                    if (nums[j] % 2 == 1) { // odd smaller
                        ok = true;
                        break;
                    }
                }
                if (!ok) return false;
            }
        }
        return true;
    }

    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return canMakeEven(nums) || canMakeOdd(nums);
    }
};