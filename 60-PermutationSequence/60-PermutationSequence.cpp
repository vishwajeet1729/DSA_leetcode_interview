// Last updated: 1/17/2026, 12:34:46 PM
class Solution {
public:
    long long fact(long i) {
        if (i == 0 || i == 1)
            return 1; // base case: 0! and 1! are both 1
        return i * fact(i - 1);
    }
    string getPermutation(int n, int k) {

        vector<int> v;
        for (int i = 1; i <= n; ++i)
            v.push_back(i);
        k--;
        string s = "";

        for (int i = n; i >= 1; --i) {

            long long x = fact(i - 1);

            int ind = k / x;
            s += (v[ind]+'0');

            v.erase(v.begin() + ind);
            k = k % x;
        }

        return s;
    }
};