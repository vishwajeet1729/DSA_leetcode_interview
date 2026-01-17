// Last updated: 1/17/2026, 12:27:26 PM
#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
          ll ct = n - 1;
    ll j = 0;
    ll ans = x;

    for (ll i = 0; i < 62; ++i) {
        if (((1ll << i) & ans) == 0) {
            ll p=((1ll << j) & ct);
            if(p>0)p=1;
            ans |= (p<< i);
            j++;
        }
    }

 return ans;
    }
};