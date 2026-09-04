class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int maxx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int minn = INT_MAX;
            maxx = max(maxx, nums[i]);

            for (int j = i; j < nums.size(); j++) {
                minn = min(minn, nums[j]);
            }
            if(maxx-minn<=k) return i;
        }


        return -1;
    }
};