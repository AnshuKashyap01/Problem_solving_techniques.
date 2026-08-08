class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        vector<int>left;
        vector<int>right;
        left.push_back(1);
        right.push_back(1);
        int n = ratings.size();
        int ans = 0;

        for(int i = 0; i+1 <ratings.size();i++){
            if(ratings[i]<ratings[i+1]) left.push_back(left[i]+1) ;
            else left.push_back(1);
        }
       
        for(int i = n-1; i>=1;i--){
            if(ratings[i]<ratings[i-1]) right.push_back(right.back()+1) ;
            else right.push_back(1);
           
        }

        reverse(right.begin(),right.end());

        int maxx = INT_MIN;
        for(int i = 0 ; i<n;i++){
            maxx= max(left[i],right[i]);
            ans+=maxx; 
        }

        return ans;

    }
};