class Solution {
public:
    bool sumGame(string num) {
         int n = num.size();
         int cntq1 = 0;
         int cntq2 = 0;
         int sum1 = 0;
         int sum2 = 0;
         
         for(int i = 0 ; i<n/2 ; i++){
            if(num[i] == '?') cntq1++;
            else{
                sum1+= num[i] - '0';
            }
         }

         for(int i = n/2 ; i<n ; i++){
            if(num[i] == '?') cntq2++;
            else{
                sum2+= num[i] - '0';
            }
        }
        int diff = sum1-sum2;

      if (cntq1 == cntq2)
            return diff != 0;

        return 2 * diff != 9 * (cntq2 - cntq1);
        

    }
};