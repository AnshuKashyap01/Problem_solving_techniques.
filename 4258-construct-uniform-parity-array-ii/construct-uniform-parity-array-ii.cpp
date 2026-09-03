class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int minn=nums1[0];
        //smallest EVEN---->
        if(minn%2==0){
                for(int i = 1 ; i<nums1.size(); i++){
                    if(nums1[i]%2!=0 && (nums1[i]-minn)%2!=0) return false;
                }
        }
    
        else if(minn%2!=0){
                for(int i = 1 ; i<nums1.size(); i++){
                    if(nums1[i]%2==0 && (nums1[i]-minn)%2==0) return false;
                }
        }

        return true;

    }
    
};