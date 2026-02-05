class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
          vector<int>res(n);
        for(int i=0;i<nums.size();i++){
            int index=((i+nums[i])%n +n ) % n;
            res[i]=nums[index];
        }
        return res;
    }
};