class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > arr[ans]){
                ans = i;
            }
        }
        return ans;
    }
};