class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxlen=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n &&nums[j]<=(long long)k*nums[i]){
                j++;
            }
            maxlen=max(maxlen,j-i);
        }    
    return n-maxlen;
    }
};