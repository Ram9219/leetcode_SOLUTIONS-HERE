class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        return pow(10,n)-9;
    }
};