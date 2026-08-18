class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans = -1;
        int maxx= INT_MIN;
        

        for(int i = 0 ; i<=nums.size()-k; i++){
            for(int j = i ; j<i+k ; j++){
                mp[nums[j]]++;
                maxx=max(maxx,nums[j]); 
            }
        }
        if(k==nums.size()) return maxx;

        for(auto it : mp){
            if(it.second == 1){
                    ans=max(ans,it.first);
            }
        }

        return ans;
    }
};