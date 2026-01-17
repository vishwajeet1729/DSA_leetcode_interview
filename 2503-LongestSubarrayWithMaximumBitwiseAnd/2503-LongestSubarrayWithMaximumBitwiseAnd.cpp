// Last updated: 1/17/2026, 12:28:57 PM

#define ll long long 
class Solution {
public:
    int longestSubarray(vector<int>& v) {
         ll n=v.size();
    // cin >> n;
    // vector<ll> v(n);
    ll mx = 0;
// for(auto &it:v)cin>>it;
    ll ct = 1;
    vector<pair<ll, ll>> ans;

    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == v[i + 1]) {ct++;}
        else {

            ans.push_back({v[i], ct});
            ct = 1;
        }
    }
    
    ans.push_back({v[n - 1], ct});
    mx = 0;
    ll op = 0;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].first > mx) {
            mx = ans[i].first;
            op = ans[i].second;
        } else if (ans[i].first == mx) {
            op = max(ans[i].second, op);
        }
    }

    // cout << op << endl;
    return (int)op;
    }
};