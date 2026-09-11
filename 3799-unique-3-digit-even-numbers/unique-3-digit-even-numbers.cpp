class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        // Choose last digit (must be even)
        for (int c = 0; c <= 8; c += 2) {

            if (freq[c] == 0)
                continue;

            freq[c]--;  // use one occurrence of c

            // Choose first digit (cannot be 0)
            for (int a = 1; a <= 9; a++) {

                if (freq[a] == 0)
                    continue;

                freq[a]--;

                // Choose middle digit
                for (int b = 0; b <= 9; b++) {
                    if (freq[b] > 0)
                        ans++;
                }

                freq[a]++;
            }

            freq[c]++;
        }

        return ans;
    }
};