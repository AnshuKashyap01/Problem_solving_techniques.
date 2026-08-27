class Solution {
public:
    void solve(vector<vector<char>>& board) {

        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector(n, 0));
        queue<pair<int, int>> q;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 'O') {
                    if (row == m - 1 || col == n - 1 || row == 0 || col == 0) {
                        q.push({row, col});
                        vis[row][col] = 1;
                    }
                }
            }
        }

        vector<int> delrow = {0, 1, 0, -1};
        vector<int> delcol = {1, 0, -1, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow < m && ncol < n && nrow >= 0 && ncol >= 0 &&
                    !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

         for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 'O' && !vis[row][col]) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};