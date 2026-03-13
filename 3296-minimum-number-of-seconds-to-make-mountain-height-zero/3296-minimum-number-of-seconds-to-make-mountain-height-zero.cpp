#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool can(long long time, int h, vector<int>& nums){
        long long removed = 0;

        for(int w : nums){
            long long k = (sqrt(1 + 8.0 * time / w) - 1) / 2;
            removed += k;
            if(removed >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int h, vector<int>& nums) {
        long long l = 0, r = 1e18, ans = r;

        while(l <= r){
            long long mid = (l + r) / 2;

            if(can(mid, h, nums)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};