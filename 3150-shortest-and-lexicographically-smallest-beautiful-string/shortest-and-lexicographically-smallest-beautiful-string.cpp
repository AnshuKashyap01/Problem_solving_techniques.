class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, cnt = 0;
        string ans = "";

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') cnt++;

            while (cnt > k) {
                if (s[i++] == '1') cnt--;
            }

            if (cnt == k) {
                while (s[i] == '0')
                    i++;

                string cur = s.substr(i, j - i + 1);

                if (ans == "" || cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans))
                    ans = cur;
            }
        }

        return ans;
    }
};