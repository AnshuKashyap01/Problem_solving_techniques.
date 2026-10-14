class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()),suffix(nums.size()),ans(nums.size());
        suffix[0] = 1;
        prefix[nums.size()-1] = 1;
        


        for(int i = 1 ; i<nums.size();i++){
            suffix[i] = suffix[i-1]*nums[i-1];
        }

        for(int i = nums.size()-2 ; i>=0;i--){
            prefix[i] = prefix[i+1]*nums[i+1];
        }

        for(int i = 0 ; i<nums.size() ; i++){
            ans[i] = suffix[i]*prefix[i];
        }

        return ans;

    }
};