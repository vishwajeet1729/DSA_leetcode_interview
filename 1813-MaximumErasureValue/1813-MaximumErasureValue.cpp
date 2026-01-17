// Last updated: 1/17/2026, 12:30:20 PM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
         set<int> s;
         int n=v.size();
    int cur_sum = 0;
    int mx = 0;
    int l = 0;
    for (int r = 0; r < n; ++r)
    {

        if (s.find(v[r]) == s.end())
        {
            s.insert(v[r]);
            cur_sum += v[r];
        }
        else
        {
            mx = max(mx, cur_sum);

            while (v[l] != v[r])
            {
                cur_sum -= v[l];
                s.erase(v[l]);
                l++;
            }
            l++;
        }
        mx = max(cur_sum, mx);
    }

return mx;
    }
};