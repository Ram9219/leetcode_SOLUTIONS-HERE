class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return false;
        unordered_set<string>str;
        for(int i=0;i<=s.length()-k;i++){
            str.insert(s.substr(i,k));//i me se k length ke substring ko insert karte jaao 
        }
        return str.size()==(1<<k);
    }
};