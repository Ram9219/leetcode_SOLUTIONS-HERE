class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans{{}};
       for(int x:nums){
        int size=ans.size();
        for(int i=0;i<size;i++){
            vector<int>temp=ans[i];
            temp.push_back(x);
            ans.push_back(temp);
        }
       }
       return ans;
    }
};