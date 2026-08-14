class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int> mpp;
     
        int i = 0;
        int j  = 0;
        int maxx = INT_MIN;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            maxx = max(maxx,j-i+1);
            j++;
        
        }
        return maxx;


    }
};