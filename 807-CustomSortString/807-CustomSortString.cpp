// Last updated: 1/17/2026, 12:32:03 PM
#include <algorithm> // For std::find
#include <string>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int j = 0;
        int n = s.size();
        int n2 = order.size();
        for (int i = 0; i < n && j < n2; ) {
            char c = order[j];
            auto it = find(s.begin() + i, s.end(), c);
            if (it != s.end()) {
                swap(s[i], *it);
                i++; 
            } else {
                j++;
            }
        }
        return s;
    }
};
