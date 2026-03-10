class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>s(begin(nums),end(nums));
        int i=0;
        while(true){
            if(s.find(i)==s.end()){
                return i;
            }
            i++;
        }
        return i;
    }
};