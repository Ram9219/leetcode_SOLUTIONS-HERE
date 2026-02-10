class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans(n+1,0);
       for(int i=1;i<=n;i++){
        int x=i;
        while(x>0){
            x=x & (x-1);
            ans[i]++;
        }
       }
        return ans;
    }
};