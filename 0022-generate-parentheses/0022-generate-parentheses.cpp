class Solution {
public:
vector<string>ans;
void generate(string &cur,int open,int close,int n){
    if(open==n &&close==n){
        ans.push_back(cur);
        return;
    }
    if(open<n){
        cur.push_back('(');
        generate(cur,open+1,close,n);
        cur.pop_back();
    }
    if(close<open){
        cur.push_back(')');
         generate(cur,open,close+1,n);
         cur.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string cur="";
        generate(cur,0,0,n);
        return ans;
    }
};