class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 2) {
                    q.push({{row, col}, 0});
                    vis[row][col] = 2;
                }
            }
        }

        int tm = 0;
        vector<int> delrow = {0, 0, -1, +1};
        vector<int> delcol = {1, -1, 0, -0};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }

        return tm;
    }
};