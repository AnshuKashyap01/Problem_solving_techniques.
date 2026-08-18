class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 ;
        vector<int> delrow = {0,0,-1 ,1};
        vector<int> delcol = {-1 ,1,0,0};
        for(int row  = 0 ; row<grid.size();row++){
            for(int col= 0 ; col<grid[0].size(); col++){
                if(grid[row][col]==1){
                    int cnt = 0 ;
                    for(int t = 0 ; t<4 ; t++){
                        int nrow = row + delrow[t];
                        int ncol = col + delcol[t];

                        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                            cnt++;
                        }
                    }

                    ans+= 4-cnt;
                    
                }

            }
        }
       

    

        return ans;
    }


};