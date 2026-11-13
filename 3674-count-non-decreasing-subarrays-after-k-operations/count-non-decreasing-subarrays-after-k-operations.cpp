class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<pair<int, int>> dq;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int cnt = 1;

            // Merge smaller elements into the current element
            while (!dq.empty() && dq.back().first < num) {

                auto [val, count] = dq.back();
                dq.pop_back();

                cnt += count;

                cost += 1LL * (num - val) * count;
            }

            dq.push_back({num, cnt});

            // Reduce window if operations exceed k
            while (cost > k) {

                auto [val, count] = dq.front();
                dq.pop_front();

                cost -= val - nums[j];
                j--;

                if (count > 1) {
                    dq.push_front({val, count - 1});
                }
            }

            // Count valid subarrays
            ans += j - i + 1;
        }

        return ans;
    }
};