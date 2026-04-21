class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mina = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                int it = abs(i - start);
                mina = min(mina , it);
            }
        }
        return mina;
    }
};