class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
      sort(nums.begin(), nums.end());
        int k = 1;
        int s = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1)
                k++;
            else if (nums[i] == nums[i - 1])
                continue;

            else {
                k = 1;
            }

            s = max(s, k);
        }

        return s;
    }
};