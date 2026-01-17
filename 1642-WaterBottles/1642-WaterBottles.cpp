// Last updated: 1/17/2026, 12:30:33 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
                return numBottles + (numBottles - 1) / (numExchange - 1);

    }
};