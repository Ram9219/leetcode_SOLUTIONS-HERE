class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>s;
        // s.insert(nums.begin(),nums.end());
        // return s.size();
        int n=nums.size();
        int k=1;
        if(nums.empty())return 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[k-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};