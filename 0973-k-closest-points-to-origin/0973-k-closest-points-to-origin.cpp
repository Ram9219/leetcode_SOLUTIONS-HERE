class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max-heap:{distance,index}
      priority_queue<pair<int,int>>p;
      for(int i=0;i<points.size();i++){
        int x=points[i][0];//x-coordinates hai ye 
        int y=points[i][1];//y-coordinates hai ye 
        int distance=x*x+y*y;
        p.push({distance,i});
        if(p.size()>k){
            p.pop();//agar size k se bada hai to pop kardo elements ko ....
        }
      }
      vector<vector<int>>ans;
      while(!p.empty()){
        ans.push_back(points[p.top().second]);
        //ye points me vo  index daal raha hai jo sabse top par hai means bada hai dist,index -->>thats why second
        p.pop();
      }
      return ans;

    }
};