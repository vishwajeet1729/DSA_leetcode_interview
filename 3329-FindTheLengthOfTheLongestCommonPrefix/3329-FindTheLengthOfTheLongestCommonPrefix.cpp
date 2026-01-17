// Last updated: 1/17/2026, 12:27:42 PM
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

       map<int, int> m1, m2;

    for (int i = 0; i < arr1.size(); ++i) {
        int x = arr1[i];
        m1[x]++; 

        int j = 10;
        while (x) {
            x = x / j; 
            if (x > 0) { 
                m1[x]++;
            }
        }
    }
    for (int i = 0; i < arr2.size(); ++i) {
        int x = arr2[i];
        m2[x]++;

        int j = 10;
        while (x) {
            x = x / j; 
            if (x > 0) {  
                m2[x]++;
            }
        }
    }

    int ans = 0;  

    for (auto it : m1) {
        if (m2.find(it.first) != m2.end()) {  
            int x = it.first;
            int ct = 0;

            while (x) {
                ct++;
                x = x / 10;
            }

            ans = max(ans, ct);
        }
    }

        return ans;
    }
};