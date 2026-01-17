// Last updated: 1/17/2026, 12:27:39 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
  int ops = 0;
        multiset<long long int> s;
        
        for (int n : nums)
            s.insert(n);
            
        while (s.size() > 1 && *s.begin() < k) {
           long long int t1 = *s.begin();
            s.erase(s.begin());
           long long int t2 = *s.begin();
            s.erase(s.begin());
            t1 *= 2;
            t1 += t2;
            s.insert(t1);
            ops++;
        }
        
        return ops;
        
    }
};