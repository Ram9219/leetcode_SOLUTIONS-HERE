class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> res;

        auto balance = [&]() {
            if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            } else if (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        };

        for (int i = 0; i < nums.size(); ++i) {
            if (small.empty() || nums[i] <= *small.rbegin()) {
                small.insert(nums[i]);
            } else {
                large.insert(nums[i]);
            }
            balance();

            if (i >= k) {
                int out = nums[i - k];
                if (small.find(out) != small.end()) {
                    small.erase(small.find(out));
                } else {
                    large.erase(large.find(out));
                }
                balance();
            }

            if (i >= k - 1) {
                if (k % 2 == 1) {
                    res.push_back((double)*small.rbegin());
                } else {
                    res.push_back(((double)*small.rbegin() + *large.begin()) / 2.0);
                }
            }
        }
        return res;
    }
};