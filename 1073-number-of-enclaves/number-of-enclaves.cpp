class Solution {

public:
    void dfs(int row, int col, vector<vector<int>>& vis,
        vector<vector<int>> &grid,vector<int>delrow,vector<int>delcol) {
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,delrow,delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        if(m==0 || n==0) return 0;
        int ans = 0 ;
        vector<int> delrow = {1, -1, 0, 0};
        vector<int> delcol = {0, 0, 1, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int col = 0; col < n; col++) {
            if (!vis[0][col] && grid[0][col] == 1)
                dfs(0, col, vis, grid,delrow,delcol);
            if (!vis[m - 1][col] && grid[m - 1][col] == 1)
                dfs(m - 1, col, vis, grid,delrow,delcol);
        }

        for (int row = 0; row < m; row++) {
            if (!vis[row][0] && grid[row][0] == 1)
                dfs(row, 0, vis, grid,delrow,delcol);
            if (!vis[row][n - 1] && grid[row][n - 1] == 1)
                dfs(row, n - 1, vis, grid,delrow,delcol);
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]==1 && vis[i][j]==0) ans++;
            }
        }

        return ans;
    }
};