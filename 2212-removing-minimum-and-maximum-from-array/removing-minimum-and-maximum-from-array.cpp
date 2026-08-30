class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxx = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());

        int maxi, mini;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxx)
                maxi = i;
            if (nums[i] == minn)
                mini = i;
        }

        int a = min(maxi, mini);
        int b = max(maxi, mini);

        int ans1 = b + 1;
        int ans2 = n - a;
        int ans3 = (a + 1) + (n - b);

        return min({ans1, ans2, ans3});
    }
};