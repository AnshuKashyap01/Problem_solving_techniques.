class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start_color = image[sr][sc];
        vector<vector<int>> vis = image;
        vis[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});

       vector<int> delrow = {0, 0, -1, +1};
        vector<int> delcol = {1, -1, 0, 0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0 ; i<4;i++){
                int nrow = row + delrow[i]; 
                int ncol= col + delcol[i]; 

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==start_color && vis[nrow][ncol]!=color){
                    vis[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return vis;



    }
};