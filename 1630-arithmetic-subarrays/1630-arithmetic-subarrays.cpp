class Solution {
public:
bool aphai(vector<int>&nums){
    int n=nums.size();
    sort(begin(nums),end(nums));
    int diff=nums[1]-nums[0];//common difference 
    for(int i=2;i<n;i++){
        if(nums[i]-nums[i-1]!=diff)return false;
    }
    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool>ans;
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            //left[i] se lekar right[i] tak temperary array me store kar rahe hai 
            vector<int>temp(begin(nums)+start,begin(nums)+end+1);//here you can use for loop 
            bool isAp=aphai(temp);
            ans.push_back(isAp);
        }
        return ans;
        
    }
};