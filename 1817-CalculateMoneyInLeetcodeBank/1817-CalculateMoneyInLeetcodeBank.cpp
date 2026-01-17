// Last updated: 1/17/2026, 12:30:18 PM
class Solution {
public:
    int totalMoney(int n) {
               return 7*(n/7)*(n/7+7)/2 + ((n%7)+(n/7))*((n%7)+(n/7)+1)/2 - (n/7)*((n/7)+1)/2;
    }
};