class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mpp;
        int i = 0;
        int j = 0;
        int maxx = INT_MIN;

        while(j<nums.size()){
            mpp[nums[j]]++;
            if(mpp[nums[j]]<=k){
                
            }
            else{
                while(mpp[nums[j]]>k){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0){
                        mpp.erase(nums[i]);
                    }
                    i++;
                }
            }
            maxx= max(maxx,j-i+1);
            j++;

        }

        return maxx;

    }
};