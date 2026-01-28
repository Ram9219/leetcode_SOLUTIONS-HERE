class Solution {
public:
    double myPow(double a, int b) {
        long long n = b;
        if (n < 0) {
            a = 1 / a;
            n = -n;
        }
        return power(a, n);
    }

    double power(double a, long long n) {
        if (n == 0) return 1;

        double half = power(a, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return a * half * half;
    }
};
