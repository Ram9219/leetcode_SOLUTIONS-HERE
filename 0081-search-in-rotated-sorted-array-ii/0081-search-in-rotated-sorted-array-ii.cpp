class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int>st(begin( nums),end(nums));
        if(st.count(target))return true;
        return false;
    }
};