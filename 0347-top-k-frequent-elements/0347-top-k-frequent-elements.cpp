class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        //aab max heap me :{frequency,elements}
        priority_queue<pair<int,int>>p;
        for(auto x:freq){
            p.push({x.second,x.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans ;

    }
};