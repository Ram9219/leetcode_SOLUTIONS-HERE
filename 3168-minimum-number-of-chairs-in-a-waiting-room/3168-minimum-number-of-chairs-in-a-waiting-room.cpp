class Solution {
public:
    int minimumChairs(string s) {
        int current=0;
        int maxchair=0;
        for(char ch:s){
            if(ch=='E'){
                current++;
                maxchair=max(maxchair,current);
            }
            else{
                current--;
            }
        }
        return maxchair;
    }
};