class Solution {
    public int numSteps(String s) {
        //by using the greedy techniques if the last bit is 1 --odd 0 -->even 
        int n=s.length();
        int carry=0;
        int steps=0;
        for(int i=n-1;i>0;i--){
            if((s.charAt(i)-'0'+carry)==1){
                //we will move the bits by 2 steps and take the carry as 1 
                steps+=2;
                carry=1;
            }
            else{
                steps+=1;
            }
        }
        //we have to rerturn the nmber of steps to find out the 1 bits 
        return steps+carry;
    }
}