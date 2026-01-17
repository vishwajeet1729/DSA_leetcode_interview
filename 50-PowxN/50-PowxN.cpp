// Last updated: 1/17/2026, 12:34:53 PM
class Solution {
public:
double my(double x, long long n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        // if (n == -1) return 1 / x;  

        double half = my(x, n / 2); 
        return half * half * (abs(n) & 1 ? x : 1);
    }

    double myPow(double x, int n) {
        n=(long long)n;
        if (n < 0) return 1/my(x, n); 
        return my(x, n);
    }
};