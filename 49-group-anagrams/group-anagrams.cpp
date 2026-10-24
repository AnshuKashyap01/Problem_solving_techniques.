class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>,vector<string>>mpp;
    for(auto it : strs){
        vector<int> cnt(26,0);
        for(auto ch : it){
            cnt[ch - 'a']++;
        }
        mpp[cnt].push_back(it);
    }

    vector<vector<string>>ans;

    for(auto it : mpp){
        ans.push_back(it.second);
    }

    return ans;

    }
};