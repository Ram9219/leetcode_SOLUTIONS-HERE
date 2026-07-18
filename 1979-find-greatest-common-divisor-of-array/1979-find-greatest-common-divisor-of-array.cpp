class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=*max_element(begin(nums),end(nums));
        int mini=*min_element(begin(nums),end(nums));
        return __gcd(maxi,mini);
    }
};