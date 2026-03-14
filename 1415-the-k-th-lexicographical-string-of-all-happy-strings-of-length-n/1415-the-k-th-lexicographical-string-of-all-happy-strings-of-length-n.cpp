class Solution {
public:
    string ans="";
    int count=0;
    void dfs(string curr,int n,int k){
        if(curr.size()==n){
            count++;
            if(count==k)ans=curr;
            return ;
        }
        for(char c='a';c<='c';c++){
            if(curr.empty() ||curr.back()!=c){
                dfs(curr+c,n,k);
            }
            if(!ans.empty())return ;
        }
    }
    string getHappyString(int n, int k) {
        dfs("",n,k);
        return ans;
    }
};