class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(auto x:freq){
            if(x!=0){
                return false;
            }
        }
        return true;
        
    }
};