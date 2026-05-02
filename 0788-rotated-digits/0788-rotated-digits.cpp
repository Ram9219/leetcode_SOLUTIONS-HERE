class Solution {
public:
bool isgood(int n){
    bool change=false;
    while(n>0){
    int digit=n%10;
    if(digit==3 ||digit==4 ||digit==7)return false;
    else if(digit==2 ||digit==5 ||digit==6 || digit==9){
        change=true;
    }
    n/=10;
    }
    return change;
}
    int rotatedDigits(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            if(isgood(i)){
                count++;
            }
        }
        return count;
    }
};