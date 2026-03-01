class Solution {
public:
    int minPartitions(string n) {
        int maxdigit=0;
        for(char ch:n){
            maxdigit=max(maxdigit,ch-'0');
        }
        return maxdigit;
    }
};