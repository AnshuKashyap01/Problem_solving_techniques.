class Solution {

private:
    bool starter(int start, vector<vector<int>>& graph, vector<int>& color) {
        
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0 ; i<graph.size() ; i++){
            if(color[i]==-1){
                if(starter(i , graph , color)==false){
                    return false;
                }

            }
        }

        return true ;
    }
};