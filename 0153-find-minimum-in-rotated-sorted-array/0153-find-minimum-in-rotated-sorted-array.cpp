class Solution {
public:
    int findMin(vector<int>& nums) {
        // priority_queue<int ,vector<int>,greater<int>>pq(begin(nums),end(nums));
        // return pq.top();
        int minn=nums[0];
        for(int i:nums){
            minn=min(minn,i);
        }
        return minn;
    }
};