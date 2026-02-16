class Solution {
public:
//hexchar lenge use p
    string toHex(int num) {
       if(num==0)return "0";
       unsigned int n=num;
       string ans="";
       string hexchar="0123456789abcdef";
       while(n>0){
        ans=hexchar[n%16]+ans;
        n/=16;
       }
       return ans;
    }
};