// Last updated: 1/17/2026, 12:27:37 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles;

        int sum=numBottles;
        while(numExchange<=empty){
            empty-=numExchange;
            numExchange++;
            sum++;
            empty++;
        }
        return sum;
    }
};