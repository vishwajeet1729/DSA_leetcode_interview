// Last updated: 1/17/2026, 12:28:13 PM
class Solution {
public:
   int differenceOfSums(int n, int m) {
    int k = n / m;
    int divisibleSum_times_2 = m * k * (k + 1);
    int totalSum = (n * (n + 1)) / 2;
    return totalSum - divisibleSum_times_2;
}
};