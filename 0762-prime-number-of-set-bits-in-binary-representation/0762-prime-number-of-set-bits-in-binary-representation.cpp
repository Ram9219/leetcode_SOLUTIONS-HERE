class Solution {
public:
bool isprime(int n){
    vector<bool>prime(n,true);
    if(n<2)return false;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    return prime[n];
}
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int setbits=__builtin_popcount(i);
            if(isprime(setbits)){
              count++;
            }
        }
        return count;
    }
};