class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        // row aur column ko 1 d array banakar serach karenge ......
        int n=arr.size();
        int m=arr[0].size();
        int left=0;
        int right=m-1;
        while(left<=right){
           if(arr[left][right]==target){
            return true;
           }
           else if(target>arr[left][right]){
            left++;
           }
           else{
            right--;
           }

        }
        return false;
    }
};