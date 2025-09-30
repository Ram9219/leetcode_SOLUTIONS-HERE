class Solution {
public:
    bool checkIfPangram(string s) {
        int mask = 0;  // 26 bits, initially all 0
    for (char ch : s) {
        if (isalpha((unsigned char)ch)) {
            mask |= 1 << (tolower(ch) - 'a');
            if (mask == (1 << 26) - 1) return true; // early stop if all found
        }
    }
    return mask == (1 << 26) - 1;
    }
};