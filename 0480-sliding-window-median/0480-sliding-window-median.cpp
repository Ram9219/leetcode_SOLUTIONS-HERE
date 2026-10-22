
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        ordered_multiset<pair<int, int>> st;

        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            st.insert({nums[j], j});

            if (j - i + 1 < k) {
                continue;
            }

            if (k % 2 == 1) {
                ans.push_back(st.find_by_order(k / 2)->first);
            } else {
                double a = st.find_by_order(k / 2 - 1)->first;
                double b = st.find_by_order(k / 2)->first;
                ans.push_back((a + b) / 2.0);
            }

            st.erase({nums[i], i});
            i++;
        }

        return ans;
    }
};
