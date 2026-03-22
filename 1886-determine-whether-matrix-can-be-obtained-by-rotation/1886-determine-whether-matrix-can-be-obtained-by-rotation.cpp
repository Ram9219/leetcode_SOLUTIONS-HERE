class Solution {
public:
void rotate(vector<vector<int>>&mat){
    int n=mat.size();
//transpose
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        swap(mat[i][j],mat[j][i]);
    }
}
//reverse each row 
for(int i=0;i<n;i++){
    reverse(begin(mat[i]),end(mat[i]));
}
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int i=0;i<4;i++){
            if(mat==target){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};