class Solution {
private:
    void bfs(vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int &ans) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {

            int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int delrow[] = {-1, 1, 0, 0};
                int delcol[] = {0, 0, -1, 1};

                for (int k = 0; k < 4; k++) {

                    int nrow = row + delrow[k];
                    int ncol = col + delcol[k];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] &&
                        grid[nrow][ncol] == 1) {

                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;

                        q.push({nrow, ncol});

                        rotten = true;
                    }
                }
            }

            if (rotten)
                ans++;
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        bfs(vis, grid, ans);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};