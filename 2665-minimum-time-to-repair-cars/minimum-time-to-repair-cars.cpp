class Solution {
public:
    vector<int> v;
    int n;
    long long cars;

    bool check(unsigned long long mid) {
        unsigned long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (unsigned long long)(sqrt(mid / v[i])); // Ensure proper sqrt calculation
            if (ans >= cars) return true; // Early stopping
        }
        return ans >= cars;
    }

    long long repairCars(vector<int>& ranks, int c) {
        v = ranks;
        cars = c;
        n = v.size();
        sort(v.begin(), v.end());

        unsigned long long l =1, h = (unsigned long long)cars * v[0] * cars, ans = 0;
        
        while (l <= h) {
            unsigned long long mid = (l + h) / 2;
            if (check(mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
