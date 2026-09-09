class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        // if(n>=1000)ans+=n-999;
        // if(n>=1000000)ans+=n-999999;
        // if(n>=1000000000)ans+=n-999999999;
        long long p=1000;
        while(p<=n){
            ans+=n-p+1;
            p*=1000;
        }
        return ans;
    }
};