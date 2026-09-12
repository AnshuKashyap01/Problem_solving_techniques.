class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& path, stack<int>& st) {
        vis[node] = 1;
        path[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, path,st) == false)
                    return false;
            } else if (path[it]) {

                return false;
                st = stack<int>();
            }
        }
        st.push(node);
        path[node] = 0;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<vector<int>> adj(n);
        stack<int> st;
        vector<int> ans;
        

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if(dfs(i, adj, vis,path,st)==false) return {};
            }
        }
        
        if (st.empty())
            return ans;
        else {
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};