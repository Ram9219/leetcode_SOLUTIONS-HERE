class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> firstUpper(26, INT_MAX);
        vector<int> lastLower(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            } else {
                firstUpper[ch - 'A'] = min(firstUpper[ch - 'A'], i);
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX &&
                lastLower[i] < firstUpper[i]) {

                ans++;
            }
        }

        return ans;
    }
};