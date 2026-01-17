// Last updated: 1/17/2026, 12:34:27 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
    int mx = 0;
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && v[s.top()] > v[i]) {
            int heightIndex = s.top();
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            mx = max(mx, v[heightIndex] * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int heightIndex = s.top();
        s.pop();
        int width = s.empty() ? n : (n - s.top() - 1);
        mx = max(mx, v[heightIndex] * width);
    }
 return mx;
    }
};