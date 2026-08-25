class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>count(128,0);
        int length=0;
        for(char c:s){
            count[c]++;
            if(count[c]%2==0){
                length+=2;
            }
        }
        if(s.length()>length){
            length+=1;
        }
        return length;
    }
};