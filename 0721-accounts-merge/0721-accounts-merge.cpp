class DisjointSet{
    public:
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int ult_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=ult_parent(parent[node]);
    }
    void find_Union_By_Rank(int u,int v){
        int pu=ult_parent(u);
        int pv=ult_parent(v);
        if(pu==pv)return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.find_Union_By_Rank(i,mp[mail]);
                }
            }
        }
        //aab merge krna rah  gaya hai 
        vector<string>mergeMail[n];
        for(auto &it:mp){
            string mail=it.first;
            int node=ds.ult_parent(it.second);
            mergeMail[node].push_back(mail);
        }

        //aab ultimate parent ko bhi same tareeke se call karte jao 

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0){
                continue;
            }
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);

        }
        return ans;

    }
};