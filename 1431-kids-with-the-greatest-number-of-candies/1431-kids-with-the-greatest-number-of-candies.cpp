class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool>ans;
        int mx=*max_element(begin(candies),end(candies));
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=mx){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};