class Solution {
public:
    int countMonobit(int n) {
    long long count=0;
     if(n>=0)count++;
     long long val=1;
     while(val<=n){
        count++;
        val=(val<<1)| 1;//right shift karna hai hame yaha 
     }
        return count;
    }
};