class Solution {
public:
    unordered_map<string, bool> mp;

    bool solve(string a, string b) {

        if (a == b)
            return true;

        if (a.size() != b.size())
            return false;

        if (a.size() <= 1)
            return false;

        string key = a + " " + b;

        if (mp.find(key) != mp.end())
            return mp[key];

        int n = a.size();

        for (int k = 1; k < n; k++) {

            // swapped
            if (solve(a.substr(0, k), b.substr(n - k)) &&
                solve(a.substr(k), b.substr(0, n - k)))
                return mp[key] = true;

            // not swapped
            if (solve(a.substr(0, k), b.substr(0, k)) &&
                solve(a.substr(k), b.substr(k)))
                return mp[key] = true;
        }

        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};