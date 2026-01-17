// Last updated: 1/17/2026, 12:30:09 PM
class Solution {
public:
    bool checkPowersOfThree(int target) {
             
              while(target){
                  int r=target%3;
                   if(r==0)target/=3;
                   else if(r==1)target/=3;
                   else return 0;
              }
              return 1;
    }
};