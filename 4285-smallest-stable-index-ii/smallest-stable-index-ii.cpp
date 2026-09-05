class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> premax(nums.size());
        vector<int> suffmin(nums.size());
        int maxx = INT_MIN;
        int minn = INT_MAX;



     for(int i = 0 ; i<nums.size() ; i++){
        maxx = max(maxx,nums[i]);
        premax[i] = maxx;
     }

     for(int i = nums.size()-1 ; i>=0 ; i--){
        minn = min(minn,nums[i]);
        suffmin[i] = minn;
     }

     for(int i = 0  ; i<nums.size() ; i++ ){
        if(premax[i]-suffmin[i]<=k) return i;
     }



    return -1;

    }
};