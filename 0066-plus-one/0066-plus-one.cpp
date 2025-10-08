class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         for (int i = digits.size() - 1; i >= 0; i--) {
            if (++digits[i] < 10)
                return digits;  // no carry needed
            digits[i] = 0;      // carry over
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};