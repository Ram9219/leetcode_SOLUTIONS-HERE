class Solution {
public:
    int concatenatedBinary(int n) {
        long long  ans=0;
        int mod=1e9+7;
        int len=0;
        for(int i=1;i<=n;i++){
            //if power of 2 then 
           if((i &(i-1))==0){
            len++;
           }
            ans=((ans<<len)+i)%mod;
        }
        return ans;
    }
};