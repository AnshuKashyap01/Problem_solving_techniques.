class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum = 0;
        int digitprod = 1;
        int temp  = n;
        while(temp){
            digitsum+=temp%10;
            digitprod*=temp%10;
            temp=temp/10;
        }
        
        if(n%(digitsum + digitprod)==0) return true;
        return false;
    }
};