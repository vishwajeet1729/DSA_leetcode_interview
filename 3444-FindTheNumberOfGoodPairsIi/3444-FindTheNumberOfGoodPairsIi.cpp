// Last updated: 1/17/2026, 12:27:12 PM
class Solution {
public:
    long long numberOfPairs(vector<int>& v1, vector<int>& v2, int k) {
        unordered_map<int, int> mp;
                long long ans = 0;
        for (int n2 : v2) {
            mp[n2*k]++;
        }
        for (int n1 :v1) {
            for (int i = 1; i*i <= n1; i++) {
                if (n1 % i == 0) {
                    int comp = n1 / i;
                    if (mp.count(i)) 
                        ans += mp[i];
                    
                    if ( mp.count(comp)&&comp != i) 
                        ans =ans+ mp[comp];
                    
                }
            }
        }

        return ans;
    }
};