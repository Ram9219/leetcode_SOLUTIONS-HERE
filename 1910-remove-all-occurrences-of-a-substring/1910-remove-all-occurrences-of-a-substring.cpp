class Solution {
public:
    string removeOccurrences(string s, string part) {
        //it will take the time complexity of O(n^2)  because find function uses the O(n) time complexity 
        while(s.find(part)!=string::npos){
            int index=s.find(part);
            s.erase(index,part.length());
        }
        return s;
    }
};