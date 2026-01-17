// Last updated: 1/17/2026, 12:33:33 PM
class Solution {
public: 
  void seive(vector<bool> &v, int n) {
        v.assign(n, true);  // Resize vector & initialize all elements as true
        if (n > 0) v[0] = false;
        if (n > 1) v[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (v[i]) {
                for (int j = i * i; j < n; j += i)
                    v[j] = false;
            }
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> v;
        seive(v, n);  // Generate primes up to 'n-1'
        return count(v.begin(), v.end(), true);  // Count true values
    }
};