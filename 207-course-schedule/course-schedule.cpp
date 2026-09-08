class Solution {
private:
    bool dfs(int node , vector<vector<int>>&adj , vector<int> &vis , vector<int>&path){
            vis[node]= 1;
            path[node]=1;

            for(auto it:adj[node]){
                if(!vis[it]){
                    if(dfs(it , adj , vis , path)==false) return false ;
                }
                else if(path[it]){
                    return false;
                }
            }

            path[node]=0;
            return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses);
        vector<int> path(numCourses);

        for(int i = 0 ; i<numCourses ; i++){
            if(!vis[i]){
                if(dfs(i , adj ,vis , path )==false ) return false ;
            }
        }

        return true;

    }
};