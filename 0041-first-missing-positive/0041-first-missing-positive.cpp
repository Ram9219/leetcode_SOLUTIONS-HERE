class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(begin(nums),end(nums));
        int ans=1;
        while(true){
             if(st.find(ans)==st.end()){
               return ans;
            }
            ans++;
        }
        return ans;
    }
};