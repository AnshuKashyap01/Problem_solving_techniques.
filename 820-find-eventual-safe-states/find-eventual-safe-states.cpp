class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<vector<int>>adjrev(V);
        vector<int> indeg(V,0);
        for(int i = 0 ; i<V ; i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;

        for(int i= 0 ; i<V ; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        vector<int> safeNodes;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int it : adjrev[node]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());

        return safeNodes;
    }
};