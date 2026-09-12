class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1],
                         intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<vector<pair<long long, vector<int>>>> dp(n + 1,
            vector<pair<long long, vector<int>>>(5));

        auto better = [](pair<long long, vector<int>>& x,
                         pair<long long, vector<int>>& y) {
            if (x.first != y.first)
                return x.first > y.first;
            return x.second < y.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Skip
                auto skip = dp[i + 1][k];

                // Take
                int j = upper_bound(starts.begin(), starts.end(), a[i][1])
                        - starts.begin();

                auto take = dp[j][k - 1];
                take.first += a[i][2];
                take.second.push_back(a[i][3]);

                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].second;
    }
};