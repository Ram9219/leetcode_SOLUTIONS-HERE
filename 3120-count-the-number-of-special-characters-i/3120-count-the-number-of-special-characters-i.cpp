class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st(begin(word),end(word));
        int count=0;
        for(char i='a';i<='z';i++){
            if(st.count(i)  && st.count(i-'a'+'A')){
                count++;
            }
        }
        return count;
    }
};