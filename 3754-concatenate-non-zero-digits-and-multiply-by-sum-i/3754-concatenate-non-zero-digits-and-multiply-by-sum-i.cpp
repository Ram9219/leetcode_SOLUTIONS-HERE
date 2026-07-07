class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        int ans;
        string x;
        long long sum=0;

        while(n){
            int last=n%10;
             sum+=last;
           if(last!=0){
            x+=to_string(last);
           }
            n/=10;
        }
        reverse(begin(x),end(x));
        return sum*(stoll(x));
    }
};