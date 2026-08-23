class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> matrix = mat;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    q.push({{row, col}, 0});
                    vis[row][col] = 1;
                }
            }
        }

        vector<int> delrow = {0, 0, 1, -1};
        vector<int> delcol = {1, -1, 0, 0};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow < m && ncol < n && ncol >= 0 && nrow >= 0 &&
                    !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    matrix[nrow][ncol]=dis+1;
                    q.push({{nrow, ncol}, dis + 1});
                    
                }
            }
        }

        return matrix;
    }
};