class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() <= 2)
            return points.size();
        
        int maxlen = 0;
        
        for(auto &point1 : points){
            
            map<pair<int,int>, int> slope;
            int duplicate = 1;   // include itself
            
            for(auto &point2 : points){
                
                int dx = point2[0] - point1[0];
                int dy = point2[1] - point1[1];
                
                if(dx == 0 && dy == 0){
                    continue;
                }
                
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                // normalize sign
                if(dx < 0){
                    dx *= -1;
                    dy *= -1;
                }
                
                slope[{dx, dy}]++;
            }
            
            int currMax = 0;
            for(auto &[sl, count] : slope){
                currMax = max(currMax, count);
            }
            
            maxlen = max(maxlen, currMax + duplicate);
        }
        
        return maxlen;
    }
};
