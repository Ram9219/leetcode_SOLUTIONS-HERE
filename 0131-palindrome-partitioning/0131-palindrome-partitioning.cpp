class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool ispal(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int index, string s) {

        // base case
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }
        // now we will try every partitioning
        for (int i = index; i < s.size(); i++) {
            if (ispal(s, index, i)) {
                // choose
                path.push_back(s.substr(index, i - index + 1));
                // explore more
                solve(i + 1, s);
                // unchoose
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
};