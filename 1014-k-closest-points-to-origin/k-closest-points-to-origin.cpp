class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxH;
        vector<vector<int>> ans;
        pair<int,vector<int>> p;

        for(auto it:points){
            int dis = (it[0]*it[0] +it[1]*it[1]);
            p = make_pair(dis,it);
            maxH.push(p);
            if(maxH.size()>k){
                maxH.pop();
            }

        }

        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        return ans;
    }
};