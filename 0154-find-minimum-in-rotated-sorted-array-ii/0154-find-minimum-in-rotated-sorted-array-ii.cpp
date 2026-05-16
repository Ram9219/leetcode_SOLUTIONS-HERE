class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq(begin(nums),end(nums));
        return pq.top();
    }
};