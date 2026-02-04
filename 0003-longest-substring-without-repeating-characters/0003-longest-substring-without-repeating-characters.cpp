class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlen=0;
        int n=s.length();
        vector<int>freq(256,-1);
        while(r<n){
            if(freq[s[r]]!=-1 && freq[s[r]]>=l){
                //duplicatre nahi hai matlab 
                     l=freq[s[r]]+1;
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
           freq[s[r]]=r;
           r++;
        }
        return maxlen;
    }
};