class Solution {
public:
    int trap(vector<int>& height) {
         int n=height.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        int trapped=0;// it will store the amount of the water is trapped -->>


        // now first we will find the leftmax array .......
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i-1]);
        }


        //now we will find the rightmax array .... to find the rightmax we have to start from  the end of the array 
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        }
//final calculation loop to find ---->>>>
for(int i=0;i<n;i++){
    int current =0;
    current=min(leftmax[i],rightmax[i])-height[i];
    if(current>=0){
        trapped+=current;
    }
}
return trapped;

    }
};