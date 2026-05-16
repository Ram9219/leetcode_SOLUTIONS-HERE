class Solution {
public:
    int lastRemaining(int n) {
        // base case  for 1 and 0 
        if(n==1 || n==0)return n;
    return 2 * (1 + n/2 - lastRemaining(n/2));

        
    }
};