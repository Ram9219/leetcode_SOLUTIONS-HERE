class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto&num:nums){
            vector<int>temp;
            while(num){
                temp.push_back(num%10);
                num/=10;
            }
            reverse(begin(temp),end(temp));
            for(int i:temp){
                ans.push_back(i);
            }
        }
        return ans;
    }
};