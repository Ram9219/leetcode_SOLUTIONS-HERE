class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;   // 1. declare vector

        for (int i = 1; i <= n; i++) {   // 2. loop from 1 to n
            if (i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                result.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                result.push_back("Buzz");
            }
            else {
                result.push_back(to_string(i));  // 4. convert number to string
            }
        }
        return result;
    }
};
