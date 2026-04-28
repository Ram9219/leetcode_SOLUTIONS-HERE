class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);//initializing as -1 
        for(int i=0;i<n;i++){
            queue<int>q;
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
            }
            while(!q.empty()){
                auto node=q.front();
                q.pop();
                for(auto x:graph[node]){
                    //agar  colorof x ==-1 ke barabar hai to use oppposite se change karo 
                    if(color[x]==-1){
                        color[x]=!color[node];
                        q.push(x);
                    }
                    else if(color[x]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};