class Solution {
public:
    // isme ham  b->yek char  ko count karke pichhe match karte huye dekhenge
    // agar pichhe avl hoga to skip karo aur last me  jo bache wahi longest hai

    int longestBalanced(string s) {
        int maxlen = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            vector<int> freq(256, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                bool flag = true;
                int target = 0;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (target == 0) {
                            target = freq[k];
                        } else if (freq[k] != target) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};