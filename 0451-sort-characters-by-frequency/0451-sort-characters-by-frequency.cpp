class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char,int>freq;
    for(auto x:s){
        freq[x]++;
    }
    vector<string>v(s.size()+1);
    for(auto x:freq){
        v[x.second].append(x.second,x.first);
    }
    string ans="";
    for(int i=s.size();i>=1;i--){
        ans+=v[i];
    }
    return ans;

    }
};