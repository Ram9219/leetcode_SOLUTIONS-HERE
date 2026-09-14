class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        x1 = rec1[0];
        x2 = rec1[2];
        x3 = rec2[0];
        x4 = rec2[2];
        y1 = rec1[1];
        y2 = rec1[3];
        y3 = rec2[1];
        y4 = rec2[3];
        if ((x1 < x4) && (x3 < x2) && (y1 < y4) && (y3 < y2)) {
            return true;
        }
        return false;
    }
};