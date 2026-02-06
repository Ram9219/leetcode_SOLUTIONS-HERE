class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char c :num){
            while(!st.empty() && st.top()>c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        //agar abhi bhi (k) bacha hai to bhagao uise 
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        //aab res me store karate chalenge 
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        //aab ise reverse  kar do  kyunki stack reverse me store karta hai 
        reverse(res.begin(),res.end());
        //leading zeros ko hata do aab 
        int i=0;
        while(i<res.size() && res[i]=='0')i++;
        res=res.substr(i);
        return res.empty()?"0":res;
    }
};