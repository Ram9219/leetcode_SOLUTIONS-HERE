class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //agar s1>s2 false;
        if(s1.size()>s2.size())return false;
        vector<int>freq1(26,0),freq2(26,0);
    for(char c:s1){
        freq1[c-'a']++;
    }
    int window=s1.size();
    for(int i=0;i<s2.size();i++){
        //add current character 
        freq2[s2[i]-'a']++;
        //remov ethe character outside the window 
        if(i>=window){
            freq2[s2[i-window]-'a']--;
        }
        if(freq1==freq2){
            return true;
        }
    }
    return false;

    }
};