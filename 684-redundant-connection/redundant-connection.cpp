class Solution {
private:
    bool dfs(int node, int target, vector<int>& vis,
             vector<vector<int>>& adj) {

        if (node == target)
            return true;

        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, target, vis, adj))
                    return true;
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto it : edges) {

            int u = it[0];
            int v = it[1];

            vector<int> vis(n + 1, 0);

      
            if (dfs(u, v, vis, adj))
                return it;

          
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};