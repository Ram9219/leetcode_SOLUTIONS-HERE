class Solution {
public:
    bool checkValidString(string s) {
        stack <int>open,stars;
        for(int i=0;i<s.length();i++){
            //open wale case ke liye dekh le 
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                stars.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!stars.empty()){
                    stars.pop();
                }
                else{return false;}
            }
        }
        //ab jo bache hai unhe dekh liya jaaye 
        while(!open.empty() && !stars.empty()){
            if(open.top()>stars.top()){
                open.pop();
                stars.pop();
            }
        }
        return open.empty();
    }
};