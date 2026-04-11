class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int color, int initcolor) {
        image[row][col] = color;

        int n = image.size();
        int m = image[0].size();

       for(int delrow=-1;delrow<=1;delrow++){
        for(int delcol=-1;delcol<=1;delcol++){
            if(abs(delrow)+abs(delcol)!=1)continue;
            int nrow=delrow+row;
            int ncol=delcol+ col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&
            image[nrow][ncol]==initcolor && image[nrow][ncol]!=color){
                dfs(nrow,ncol,image,color,initcolor);
            }
        }
       }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initcolor = image[sr][sc];
        if (initcolor == color) return image;

        dfs(sr, sc, image, color, initcolor);

        return image;
    }
};