class Cmp {
public:
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp> minH;
        pair<int, string> p;
        vector<string> ans;
        for (auto it : words) {
            mp[it]++;
        }

        for (auto it : mp) {
            p = make_pair(it.second, it.first);
            minH.push(p);
            if (minH.size() > k) {
                minH.pop();
            }
        }

        while (!minH.empty()) {
            ans.push_back(minH.top().second);
            minH.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};