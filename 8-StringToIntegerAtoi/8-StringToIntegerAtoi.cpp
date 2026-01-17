// Last updated: 1/17/2026, 12:35:26 PM
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int n = s.size();
        long cur = 0; 
        int pos = 1;
        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            pos = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            cur = cur * 10 + (s[i] - '0');
            if (cur * pos > INT_MAX) return INT_MAX;
            if (cur * pos < INT_MIN) return INT_MIN;
            i++;
        }

        return cur * pos;
    }
};
