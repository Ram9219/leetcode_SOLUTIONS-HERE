class Solution {
public:
    string decodeString(string s) {
        stack<int>numstack;
        stack<string>strstack;
        int num=0;
        string curr="";
        for(char c:s){
            if(isdigit(c)){
                num=10*num+(c-'0');
            }
            else if(c=='['){
                numstack.push(num);
                strstack.push(curr);
                num=0;
                curr="";
            }
            else if(c==']'){
                int repeat=numstack.top();
                numstack.pop();
                string temp=curr;
                for(int i=1;i<repeat;i++){
                    curr+=temp;
                    
                }
                curr=strstack.top()+curr;
                strstack.pop();
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};