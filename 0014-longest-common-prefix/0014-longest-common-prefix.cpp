class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        string first=strs[0];
        string last=strs.back();
        string ans="";
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                break;
            }
            ans+=first[i];
        }
        return ans;
    }
};