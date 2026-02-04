class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int,vector<int>,greater<int>>p;
        for(auto& i: matrix){
          for(auto x:i){
            p.push(x);
          }
        }
        while(k>1){
            p.pop();
            k--;
        }
        return p.top();
    }
};