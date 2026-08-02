class Solution {
public:
    int trap(vector<int>& height) {
        
        int left=0;
        int right=height.size()-1;
        int water=0,leftmax=0,rightmax=0;
        while(left<=right){
            if(leftmax<=rightmax){
                leftmax=max(leftmax,height[left]);
                water+=leftmax-height[left];
                left++;
            }else{
                rightmax=max(rightmax,height[right]);
                water+=rightmax-height[right];
                right--;
            }
        }
        return water;
    }
};