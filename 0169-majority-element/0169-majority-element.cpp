class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &x:nums){
            freq[x]++;
        }
        priority_queue<pair<int,int>>p;
        for(auto i:freq){
            p.push({i.second,i.first});
        }
        return p.top().second;
    }
};