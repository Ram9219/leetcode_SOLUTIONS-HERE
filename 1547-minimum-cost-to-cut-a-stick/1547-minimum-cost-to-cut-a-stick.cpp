#define pb push_back
class Solution {
public:
int dp[1001][1002];
    int solve(int i, int j, vector<int>& cuts) {
        if (i + 1 == j)
            return 0;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            // i-->k jayega
            // k-->j jayega
            int temp =
                solve(i, k, cuts) + solve(k , j, cuts) + (cuts[j] - cuts[i]);
            ans = min(ans, temp); 
       }
        return dp[i][j]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.pb(0);
        cuts.pb(n);
        int m = cuts.size();
        sort(begin(cuts), end(cuts));
        return solve(0, m - 1, cuts);
    }
};