class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>s1,s2;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            s1.insert(A[i]);
            s2.insert(B[i]);
            int count=0;
            for(auto x:s1){
                if(s2.count(x)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};