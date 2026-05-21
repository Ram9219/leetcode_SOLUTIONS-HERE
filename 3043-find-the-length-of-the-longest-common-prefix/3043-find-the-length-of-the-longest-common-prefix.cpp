class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int maxi = 0;
        // pahle array 1 ko set me store karfa lenge
        for (auto& x : arr1) {
            string s = to_string(x);
            string temp = "";
            for (char ch : s) {
                temp += ch;
                st.insert(temp);
            }
        }

        // aab arr2 me check karte chalenge
        for (auto& x : arr2) {
            string s = to_string(x);
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                temp += s[i];
                if (st.count(temp)) {
                    maxi = max(maxi, i + 1);
                }
            }
        }
        return maxi;
    }
};