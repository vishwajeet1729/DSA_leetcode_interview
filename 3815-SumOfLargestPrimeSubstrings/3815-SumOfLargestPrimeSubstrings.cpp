// Last updated: 1/17/2026, 12:25:40 PM
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool p(long long x) {
        if (x <= 1) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        long long r = sqrt(x);
        for (long long i = 3; i <= r; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string t = s.substr(i, j - i + 1);
                long long x = stoll(t);
                if (p(x)) st.insert(x);
            }
        }
        vector<long long> v(st.begin(), st.end());
        sort(v.rbegin(), v.rend());
        long long res = 0;
        for (int i = 0; i < min(3, (int)v.size()); ++i) res += v[i];
        return res;
    }
};
