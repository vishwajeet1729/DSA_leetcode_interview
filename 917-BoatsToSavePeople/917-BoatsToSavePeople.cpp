// Last updated: 1/17/2026, 12:31:51 PM

class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        multiset<int> s;
        for(int i = 0; i < p.size(); ++i)
            s.insert(p[i]);
        int ct = 0;
        while (s.size() > 1) {
            auto it1 = s.begin();
            int x = *it1;
            s.erase(it1);
            auto it = s.lower_bound(limit - x);
            if (it != s.end() && *it == limit - x) {
                ct++;
                s.erase(it);
            } else {
                if (it == s.begin()) {
                    ct++;
                } else {
                    --it;
                    s.erase(it);
                    ct++;
                }
            }
        }
        ct += (s.size() > 0); 
        return ct;
    }
};


