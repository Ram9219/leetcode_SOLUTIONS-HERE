class Solution {
public:
int sum(int n){
    int sum=0;
   while(n){
    int last=n%10;
    sum+=last;
    n/=10;
   }
   return sum;
}
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto &it:nums){
            ans=min(ans,sum(it));
        }
        return ans;
    }
};