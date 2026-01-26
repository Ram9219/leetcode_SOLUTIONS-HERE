class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        //method 1 O(n) me 
        // int sum=(n*(n+1))/2;
        // int arr=0;
        // for(int i=0;i<nums.size();i++){
        //     arr+=nums[i];
        // }
        // return sum-arr;
        //method 2 O(log n).....
        sort(nums.begin(),nums.end());
    int left=0,right=n-1;
    int missing =n;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==mid){
            left=mid+1;
        }
        else{
            missing=mid;
            right=mid-1;
        }
    }
    return missing;
    }
    
};