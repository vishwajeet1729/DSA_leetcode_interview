// Last updated: 1/17/2026, 12:27:32 PM
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
          int sum=0;
          int p=x;
           while(x){
            sum+=x%10;
            x/=10;
           }
           if(p%sum==0)return sum;
           else return -1;
    }
};