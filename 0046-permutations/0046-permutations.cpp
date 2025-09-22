class Solution {
public:
void getpermute(vector<int>&nums,int idx,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back({nums});
        return ;

    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);//  current index aur element ke swapping 
        getpermute(nums,idx+1,ans);
        swap(nums[idx],nums[i]);//backtracking step----->>>>
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getpermute(nums,0,ans);
        return ans;
    }
};