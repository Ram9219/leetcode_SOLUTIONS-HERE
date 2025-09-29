class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> mapS(256, -1);  // mapping from s -> t
        vector<int> mapT(256, -1);  // mapping from t -> s

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // If not mapped yet, assign mapping
            if (mapS[c1] == -1 && mapT[c2] == -1) {
                mapS[c1] = c2;
                mapT[c2] = c1;
            }
            // If already mapped, check consistency
            else if (mapS[c1] != c2 || mapT[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};