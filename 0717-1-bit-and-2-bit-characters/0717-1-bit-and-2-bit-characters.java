class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        int n = bits.length;

        while (i < n - 1) {    // process until the last bit
            if (bits[i] == 1) {
                i += 2;        // skip 2 bits
            } else {
                i += 1;        // skip 1 bit
            }
        }

        return i == n - 1;     // true → last character is one-bit
    }
}
