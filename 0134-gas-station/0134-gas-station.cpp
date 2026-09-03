class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalgas = accumulate(begin(gas), end(gas), 0);
        int totalcost = accumulate(begin(cost), end(cost), 0);

        if (totalgas < totalcost) {
            return -1;
        }
        int start = 0;
        int curr = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr = curr + gas[i] - cost[i];
            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }
        return start;
    }
};