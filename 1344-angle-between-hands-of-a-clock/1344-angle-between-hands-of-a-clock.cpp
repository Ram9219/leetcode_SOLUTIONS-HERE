class Solution {
public:
    double angleClock(int hour, int minutes) {
        double diff =abs(30*(hour%12 )-5.5*minutes);
        return min(diff,360-diff);
    }
};