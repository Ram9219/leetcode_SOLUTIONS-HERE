class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill '?' with 'a'
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 3: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool broken = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int idx = i + j;

                        if (!fixed[idx]) { // only change if not fixed by T
                            word[idx] = (word[idx] == 'a') ? 'b' : 'a';
                            broken = true;
                            break;
                        }
                    }

                    if (!broken) return "";
                }
            }
        }

        return word;
    }
};