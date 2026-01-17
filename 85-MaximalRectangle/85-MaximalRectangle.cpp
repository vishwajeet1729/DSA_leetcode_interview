// Last updated: 1/17/2026, 12:34:26 PM
class Solution {
public:
   int hist(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0); 
    int max_area = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            max_area = max(max_area, h * width);
        }
        s.push(i);
    }

    heights.pop_back();
    return max_area;
}

    int maximalRectangle(vector<vector<char>>& graph) {

          int n = graph.size();
    int m = graph[0].size();
    vector<int> height(m, 0);
    int max_rect = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            height[j] = (graph[i][j] == '1') ? height[j] + 1 : 0;
        }
        max_rect = max(max_rect, hist(height));
    }   
    return max_rect;
    }
};