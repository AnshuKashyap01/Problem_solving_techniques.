class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = k;

        while(true){
            if(find(nums.begin(), nums.end(), ans) != nums.end()){
                ans += k;
            }
            else{
                return ans;
            }
        }
    }
};