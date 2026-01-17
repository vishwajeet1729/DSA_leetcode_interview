// Last updated: 1/17/2026, 12:26:10 PM
// #include <bits/stdc++.h>
// using namespace std;

#define vall(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second

class Solution {
public:
    bool check(vector<pair<int, int>>& v) {
        int ct = 1;
        int last_mx=v[0].second;
        for (int i =1; i < v.size() ; ++i) {
            if (v[i].first>=last_mx){
                last_mx=max(last_mx,v[i].second);
                ct++;
            }
            else last_mx = max(last_mx, v[i].second);
        }
        return ct >= 3;  // We need at least three separate sections
    }

    bool checkValidCuts(int n, vector<vector<int>>& v) {
        int m = v.size();
        vector<pair<int, int>> y;
        
        // Extract (start_y, end_y) for checking horizontal cuts
        for (int i = 0; i < m; ++i) {
            y.pb({v[i][1], v[i][3]});
        }
        sort(vall(y));

        bool ans = check(y);

        y.clear();
        // Extract (start_x, end_x) for checking vertical cuts
        for (int i = 0; i < m; ++i) {
            y.pb({v[i][0], v[i][2]});
        }
        sort(vall(y));

        ans |= check(y);
        
        return ans;
    }
};
