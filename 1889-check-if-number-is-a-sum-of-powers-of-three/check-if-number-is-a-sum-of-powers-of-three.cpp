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