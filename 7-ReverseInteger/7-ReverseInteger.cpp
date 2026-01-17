// Last updated: 1/17/2026, 12:35:27 PM
class Solution {
public:
   int reverse(int x) {
   long  long result = 0;

    while (x != 0) {
        int digit = x % 10;
        x = x / 10;

        if (result > INT_MAX|| result < INT_MIN) {
            return 0; // Overflow detected
        }

       

        result = result * 10 + digit;
    }
   if (result > INT_MAX || result < INT_MIN) {
        return 0; // Overflow detected after reversal
    }
    return (int)result;
}

};