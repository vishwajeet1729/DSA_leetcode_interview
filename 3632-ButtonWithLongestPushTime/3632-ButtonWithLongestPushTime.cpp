// Last updated: 1/17/2026, 12:26:19 PM
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& e) {
            int mt = e[0][1];
    int sb = e[0][0];
    
    for (int i = 1; i < e.size(); ++i) {
        int t = e[i][1] - e[i-1][1]; 
        if (t > mt || (t == mt && e[i][0] < sb)) {
            mt = t;
            sb = e[i][0];
        }
    }
    
    return sb;
        
    }
};