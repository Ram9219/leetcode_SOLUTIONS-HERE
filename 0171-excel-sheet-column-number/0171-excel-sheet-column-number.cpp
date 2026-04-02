class Solution {
public:
    int titleToNumber(string str) {
        int result=0;
        for(char c:str){
            int value=c-'A'+1;
            result=result*26+value;
        }
        return result;
    }
};