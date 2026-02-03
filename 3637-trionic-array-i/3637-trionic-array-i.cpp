class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        //1 increasing | 2 decreasing | 3 increasing 
        int n=nums.size();
        if(n<4)return false;
        int i=0;
        //increasing ka case 
        while( i+1<n &&  nums[i]<nums[i+1])i++;
         if(i==0 || i==n-1)return false;
        //decreasing wala case
        while(i+1<n && nums[i]>nums[i+1])i++;
        if(i==n-1)return false;
         //increasing ka case 
         while( i+1<n &&  nums[i]<nums[i+1])i++;
        return i==n-1;;

    }
};