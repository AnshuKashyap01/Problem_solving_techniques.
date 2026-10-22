class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hsh;
        if(nums.size()==1) return false;

        for(auto it : nums){
            if(hsh.find(it)!=hsh.end()){
                return true;
            }
            hsh.insert(it); 
        }

        return false;
    }
};