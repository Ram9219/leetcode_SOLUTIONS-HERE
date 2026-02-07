class Solution {
public:
    int minimumDeletions(string s) {
        int countb=0;
        int ans=0;
        for(char c:s){
            if(c=='b')countb++;
            else{
       //c=='a' aaya tab ise hata do aur min nikalo ki isme se kaun kam hoga 
       ans=min(ans+1,countb);//ans+1 ka matlab hai ki hamne a ko remove kar diya 
            }
        }
        return ans;
    }
};