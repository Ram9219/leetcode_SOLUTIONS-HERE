class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        //sort kar do 
        sort(begin(intervals),end(intervals));
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            //agar end chhota hai pahle ke uinterval ke last wale se to aage badh jao 
            if(!ans.empty() && end<= ans.back()[1]){
                continue;
            }
            for(int  j=i+1;j<n;j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};