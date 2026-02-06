class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
         unordered_map<char, char> match = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for(char c:s){
            if(match.count(c)){
                if(st.empty() || st.top()!=match[c])return false;
                st.pop();
            }
            else{
                st.push(c);
        }
            }
        return st.empty();
    }
};