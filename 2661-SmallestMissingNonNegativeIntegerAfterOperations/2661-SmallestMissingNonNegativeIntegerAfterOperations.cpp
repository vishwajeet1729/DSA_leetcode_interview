// Last updated: 1/17/2026, 12:28:39 PM
class Solution {
public:
    int findSmallestInteger(vector<int>& arr, int value) {
        unordered_map<int,int> m;
        for (auto it : arr) {
            int r = ((it % value) + value) % value; 
            m[r]++;
        }

        int ind = 0;
        while (true) {
            int r = ind % value;
            if (m[r] == 0) return ind;
            m[r]--;
            ind++;
        }
    }
};
