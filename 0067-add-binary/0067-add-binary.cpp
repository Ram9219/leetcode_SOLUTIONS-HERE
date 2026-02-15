class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int carryout=0;
        string s="";
        while(i>=0 || j>=0|| carryout){
            int sum=carryout;
            if(i>=0){
                sum+=a[i--]-'0';
            }
            if(j>=0){
                sum+=b[j--]-'0';
            }
            s+=(sum%2)+'0';
            carryout=(sum/2);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};