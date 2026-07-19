class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26, 0), freq(26, 0);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        string st = "";
        for (auto ch : s) {
            freq[ch - 'a']--;
            if (vis[ch - 'a'])
                continue;
            // that means already found the ans
            while (!st.empty() && freq[st.back() - 'a'] > 0 && st.back() > ch) {
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }
            st.push_back(ch);
            vis[ch - 'a'] = 1;
        }
        return st;
    }
};