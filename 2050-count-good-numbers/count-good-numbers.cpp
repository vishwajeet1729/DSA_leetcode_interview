class Solution {
public:    
    long long power(long long a, long long b, long long mod) {
        long long result = 1;
        a = a % mod; 
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % mod;  // If b is odd
            }
            a = (a * a) % mod; 
            b /= 2;  
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long ans = 1;

        // For 5^(ceil(n/2))
        long long powerOf5 = (n + 1) / 2;  // Equivalent to ceil(n / 2)
        // For 4^(n/2)
        long long powerOf4 = n / 2;

        ans = (ans * power(5, powerOf5, mod)) % mod;
        ans = (ans * power(4, powerOf4, mod)) % mod;

        return ans;
    }
};
