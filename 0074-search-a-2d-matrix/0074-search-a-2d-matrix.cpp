class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        int left=0;
        int right=n*m-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int row=mid/m;
            int col=mid%m;
            if(arr[row][col]==target){
                return true;
            }
            else if(target>arr[row][col]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target|| matrix[j][i]==target){
        //             return true;
        //         }
        //     }
        // }//ye raha brute force approach 
        // return false;
    }
};