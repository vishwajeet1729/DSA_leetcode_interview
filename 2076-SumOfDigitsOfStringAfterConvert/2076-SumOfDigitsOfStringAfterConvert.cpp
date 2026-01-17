// Last updated: 1/17/2026, 12:29:59 PM
class Solution {
public:
    int repeat(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        int sum = 0;

        for (char c : s) {
            int value = (c - 'a') + 1;
            sum += repeat(value);
        }

        while (k > 1) {
            sum = repeat(sum);
            k--;
        }

        return sum;
    }
};