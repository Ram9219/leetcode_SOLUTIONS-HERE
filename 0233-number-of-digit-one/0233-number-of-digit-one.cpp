class Solution {
public:
    int countDigitOne(int org) {
        long long count = 0, factor = 1, rem = 0, n = org;
        while (n > 0) {
            long long temp = factor;
            if (n % 10 == 0) {
                rem = 0;
            } else if (n % 10 > 1) {
                rem = temp;
            } else if (n % 10 == 1) {
                rem = (org % temp) + 1;
            }
            factor *= 10;
            count += (org / factor) * temp + rem;
            n /= 10;
        }
        return count;
    }
};