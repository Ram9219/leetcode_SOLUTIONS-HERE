class Solution {
    public int climbStairs(int n) {
       int current=0;
       int way1=2;//f(2)
       int way2=1;//f(1)
       if(n<=2)return n;
       for(int i=3;i<=n;i++){
        current=way1+way2;
        way2=way1;
        way1=current;
       }
       return current;
    }
}