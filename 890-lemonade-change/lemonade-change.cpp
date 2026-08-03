class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(int it : bills){
                if(it == 5) five++;

                else if(it==10){
                    ten++;
                    if(five!=0) five--;
                    else return false;
                }
                else{
                    twenty++;
                    if(ten!=0 && five!=0){
                        ten--;
                        five--;
                    }else if(five>=3){
                        five = five-3;
                    }
                    else return false;
                }

        }

         return true;
        

      
    }
};